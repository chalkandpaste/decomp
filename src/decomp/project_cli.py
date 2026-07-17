import argparse
from collections.abc import Sequence

from .architectures import list_architectures
from .project_state import (
    add_ai_suggestion,
    add_note,
    connect,
    export_names,
    initialize,
    list_functions,
    rename_function,
)


def cmd_init(args: argparse.Namespace) -> None:
    conn = initialize(
        args.project,
        binary_path=args.binary,
        architecture=args.architecture,
        base_address=args.base_address,
        entry_point=args.entry_point,
    )
    conn.close()
    print(f"initialized {args.project}")


def cmd_arches(_args: argparse.Namespace) -> None:
    for arch in list_architectures():
        print(f"{arch.id}\t{arch.status}\t{arch.display_name}")


def cmd_rename(args: argparse.Namespace) -> None:
    conn = connect(args.project)
    rename_function(conn, args.address, args.name, confidence=args.confidence)
    conn.close()
    print(f"renamed {args.address} -> {args.name}")


def cmd_note(args: argparse.Namespace) -> None:
    conn = connect(args.project)
    add_note(conn, args.address, args.note)
    conn.close()
    print(f"noted {args.address}")


def cmd_suggest(args: argparse.Namespace) -> None:
    conn = connect(args.project)
    suggestion_id = add_ai_suggestion(
        conn,
        args.address,
        args.kind,
        args.suggestion,
        rationale=args.rationale,
        confidence=args.confidence,
    )
    conn.close()
    print(f"suggestion {suggestion_id} recorded for {args.address}")


def cmd_list(args: argparse.Namespace) -> None:
    conn = connect(args.project)
    for row in list_functions(conn):
        addr = hex(row["address"])
        name = row["name"] or "<unnamed>"
        status = row["status"]
        signature = row["signature"] or ""
        print(f"{addr}\t{status}\t{name}\t{signature}")
    conn.close()


def cmd_export_names(args: argparse.Namespace) -> None:
    conn = connect(args.project)
    export_names(conn, args.output)
    conn.close()
    print(f"exported names to {args.output}")


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        prog="decomp-project",
        description="manage decompiler project state",
    )
    sub = parser.add_subparsers(dest="command", required=True)

    p = sub.add_parser("init", help="initialize a decompiler project state database")
    p.add_argument("project")
    p.add_argument("--binary")
    p.add_argument("--architecture", default="arm-thumb")
    p.add_argument("--base-address")
    p.add_argument("--entry-point")
    p.set_defaults(func=cmd_init)

    p = sub.add_parser("architectures", help="list known architecture targets")
    p.set_defaults(func=cmd_arches)

    p = sub.add_parser("rename", help="rename a function")
    p.add_argument("project")
    p.add_argument("address")
    p.add_argument("name")
    p.add_argument("--confidence", type=float)
    p.set_defaults(func=cmd_rename)

    p = sub.add_parser("note", help="attach a note to a function")
    p.add_argument("project")
    p.add_argument("address")
    p.add_argument("note")
    p.set_defaults(func=cmd_note)

    p = sub.add_parser("suggest", help="record an AI or heuristic suggestion")
    p.add_argument("project")
    p.add_argument("address")
    p.add_argument("kind")
    p.add_argument("suggestion")
    p.add_argument("--rationale")
    p.add_argument("--confidence", type=float)
    p.set_defaults(func=cmd_suggest)

    p = sub.add_parser("list", help="list functions in project state")
    p.add_argument("project")
    p.set_defaults(func=cmd_list)

    p = sub.add_parser("export-names", help="export named functions as JSON")
    p.add_argument("project")
    p.add_argument("output")
    p.set_defaults(func=cmd_export_names)

    return parser


def main(argv: Sequence[str] | None = None) -> None:
    parser = build_parser()
    args = parser.parse_args(argv)
    args.func(args)


if __name__ == "__main__":
    main()
