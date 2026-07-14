import json
import tempfile
import unittest
from pathlib import Path

from project_state import (
    add_ai_suggestion,
    add_note,
    connect,
    export_names,
    get_metadata,
    initialize,
    list_functions,
    rename_function,
)


class ProjectStateTests(unittest.TestCase):
    def test_initialize_and_rename_function(self):
        with tempfile.TemporaryDirectory() as temp_dir:
            db_path = Path(temp_dir) / "state.sqlite"
            conn = initialize(
                db_path,
                binary_path="DD2.1.0.bin",
                architecture="arm-thumb",
                base_address="0x08020000",
                entry_point="0x080202cc",
            )

            rename_function(conn, "0x08034f48", "system_clock_init", confidence=0.9)
            add_note(conn, "0x08034f48", "writes CPACR and RCC registers")
            suggestion_id = add_ai_suggestion(
                conn,
                "0x08034f48",
                "function_name",
                "clock_tree_init",
                rationale="touches RCC registers",
                confidence=0.7,
            )

            metadata = get_metadata(conn)
            functions = list_functions(conn)

            self.assertEqual(metadata["architecture"], "arm-thumb")
            self.assertEqual(functions[0]["address"], 0x08034F48)
            self.assertEqual(functions[0]["name"], "system_clock_init")
            self.assertEqual(functions[0]["status"], "named")
            self.assertEqual(suggestion_id, 1)

            conn.close()
            reopened = connect(db_path)
            self.assertEqual(list_functions(reopened)[0]["name"], "system_clock_init")
            reopened.close()

    def test_export_names_as_json(self):
        with tempfile.TemporaryDirectory() as temp_dir:
            db_path = Path(temp_dir) / "state.sqlite"
            output_path = Path(temp_dir) / "names.json"
            conn = initialize(db_path)
            rename_function(conn, "0x08034f48", "system_clock_init")

            export_names(conn, output_path)

            payload = json.loads(output_path.read_text())
            self.assertEqual(payload["functions"][0]["address"], "0x8034f48")
            self.assertEqual(payload["functions"][0]["name"], "system_clock_init")


if __name__ == "__main__":
    unittest.main()
