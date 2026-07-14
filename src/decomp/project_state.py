import json
import sqlite3
from datetime import datetime, timezone
from pathlib import Path

from .architectures import get_architecture


SCHEMA_VERSION = 1


def utc_now():
    return datetime.now(timezone.utc).isoformat(timespec="seconds")


def parse_address(value):
    if isinstance(value, int):
        return value
    return int(value, 0)


def format_address(value):
    return hex(value)


def connect(db_path):
    path = Path(db_path)
    if path.parent != Path("."):
        path.parent.mkdir(parents=True, exist_ok=True)
    conn = sqlite3.connect(path)
    conn.row_factory = sqlite3.Row
    return conn


def initialize(db_path, *, binary_path=None, architecture="arm-thumb", base_address=None, entry_point=None):
    get_architecture(architecture)
    conn = connect(db_path)
    with conn:
        conn.executescript(
            """
            CREATE TABLE IF NOT EXISTS metadata (
                key TEXT PRIMARY KEY,
                value TEXT NOT NULL
            );

            CREATE TABLE IF NOT EXISTS functions (
                address INTEGER PRIMARY KEY,
                name TEXT,
                status TEXT NOT NULL DEFAULT 'unknown',
                signature TEXT,
                summary TEXT,
                confidence REAL,
                created_at TEXT NOT NULL,
                updated_at TEXT NOT NULL
            );

            CREATE TABLE IF NOT EXISTS symbols (
                address INTEGER PRIMARY KEY,
                name TEXT NOT NULL,
                kind TEXT NOT NULL DEFAULT 'unknown',
                notes TEXT,
                updated_at TEXT NOT NULL
            );

            CREATE TABLE IF NOT EXISTS function_notes (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                address INTEGER NOT NULL,
                note TEXT NOT NULL,
                created_at TEXT NOT NULL
            );

            CREATE TABLE IF NOT EXISTS ai_suggestions (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                address INTEGER NOT NULL,
                kind TEXT NOT NULL,
                suggestion TEXT NOT NULL,
                rationale TEXT,
                confidence REAL,
                status TEXT NOT NULL DEFAULT 'pending',
                created_at TEXT NOT NULL,
                updated_at TEXT NOT NULL
            );
            """
        )
        set_metadata(conn, "schema_version", str(SCHEMA_VERSION))
        set_metadata(conn, "architecture", architecture)
        if binary_path is not None:
            set_metadata(conn, "binary_path", str(binary_path))
        if base_address is not None:
            set_metadata(conn, "base_address", format_address(parse_address(base_address)))
        if entry_point is not None:
            set_metadata(conn, "entry_point", format_address(parse_address(entry_point)))
    return conn


def set_metadata(conn, key, value):
    conn.execute(
        """
        INSERT INTO metadata (key, value)
        VALUES (?, ?)
        ON CONFLICT(key) DO UPDATE SET value = excluded.value
        """,
        (key, value),
    )


def get_metadata(conn):
    rows = conn.execute("SELECT key, value FROM metadata ORDER BY key").fetchall()
    return {row["key"]: row["value"] for row in rows}


def upsert_function(conn, address, *, name=None, status=None, signature=None, summary=None, confidence=None):
    address = parse_address(address)
    now = utc_now()
    existing = conn.execute(
        "SELECT address FROM functions WHERE address = ?",
        (address,),
    ).fetchone()

    if existing is None:
        conn.execute(
            """
            INSERT INTO functions
                (address, name, status, signature, summary, confidence, created_at, updated_at)
            VALUES (?, ?, ?, ?, ?, ?, ?, ?)
            """,
            (address, name, status or "unknown", signature, summary, confidence, now, now),
        )
        return

    updates = {"updated_at": now}
    for key, value in {
        "name": name,
        "status": status,
        "signature": signature,
        "summary": summary,
        "confidence": confidence,
    }.items():
        if value is not None:
            updates[key] = value

    assignments = ", ".join(f"{key} = ?" for key in updates)
    values = list(updates.values()) + [address]
    conn.execute(
        f"UPDATE functions SET {assignments} WHERE address = ?",
        values,
    )


def rename_function(conn, address, name, *, confidence=None):
    with conn:
        upsert_function(
            conn,
            address,
            name=name,
            status="named",
            confidence=confidence,
        )


def add_note(conn, address, note):
    address = parse_address(address)
    now = utc_now()
    with conn:
        upsert_function(conn, address)
        conn.execute(
            "INSERT INTO function_notes (address, note, created_at) VALUES (?, ?, ?)",
            (address, note, now),
        )


def add_ai_suggestion(conn, address, kind, suggestion, *, rationale=None, confidence=None):
    address = parse_address(address)
    now = utc_now()
    with conn:
        upsert_function(conn, address)
        cursor = conn.execute(
            """
            INSERT INTO ai_suggestions
                (address, kind, suggestion, rationale, confidence, status, created_at, updated_at)
            VALUES (?, ?, ?, ?, ?, 'pending', ?, ?)
            """,
            (address, kind, suggestion, rationale, confidence, now, now),
        )
    return cursor.lastrowid


def set_suggestion_status(conn, suggestion_id, status):
    if status not in {"pending", "accepted", "rejected"}:
        raise ValueError("suggestion status must be pending, accepted, or rejected")
    with conn:
        conn.execute(
            "UPDATE ai_suggestions SET status = ?, updated_at = ? WHERE id = ?",
            (status, utc_now(), suggestion_id),
        )


def list_functions(conn):
    rows = conn.execute(
        """
        SELECT address, name, status, signature, summary, confidence
        FROM functions
        ORDER BY address
        """
    ).fetchall()
    return [dict(row) for row in rows]


def export_names(conn, output_path):
    payload = {
        "metadata": get_metadata(conn),
        "functions": [
            {
                **row,
                "address": format_address(row["address"]),
            }
            for row in list_functions(conn)
            if row["name"]
        ],
    }
    Path(output_path).write_text(json.dumps(payload, indent=2, sort_keys=True) + "\n")
    return payload
