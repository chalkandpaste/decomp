import ast
from pathlib import Path
import unittest


class TypeAnnotationCoverageTests(unittest.TestCase):
    def test_all_project_functions_have_explicit_signatures(self) -> None:
        missing = []
        for root in (Path("src/decomp"), Path("tests")):
            for path in sorted(root.rglob("*.py")):
                missing.extend(_missing_annotations(path))

        self.assertEqual(missing, [])

    def test_project_does_not_import_typing_any(self) -> None:
        imports = []
        for root in (Path("src/decomp"), Path("tests")):
            for path in sorted(root.rglob("*.py")):
                imports.extend(_typing_any_imports(path))

        self.assertEqual(imports, [])

    def test_legacy_records_use_attribute_access(self) -> None:
        violations = []
        for root in (Path("src/decomp"), Path("tests")):
            for path in sorted(root.rglob("*.py")):
                violations.extend(_legacy_record_string_key_access(path))

        self.assertEqual(violations, [])

    def test_meta_blocks_use_typed_records(self) -> None:
        violations = []
        for root in (Path("src/decomp"), Path("tests")):
            for path in sorted(root.rglob("*.py")):
                violations.extend(_meta_block_dict_usage(path))

        self.assertEqual(violations, [])


def _missing_annotations(path: Path) -> list[str]:
    missing = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if not isinstance(node, (ast.FunctionDef, ast.AsyncFunctionDef)):
            continue
        if node.returns is None:
            missing.append(f"{path}:{node.lineno} {node.name} missing return annotation")
        for arg in _function_arguments(node):
            if arg.arg in {"self", "cls"}:
                continue
            if arg.annotation is None:
                missing.append(f"{path}:{arg.lineno} {node.name}.{arg.arg} missing annotation")
    return missing


def _typing_any_imports(path: Path) -> list[str]:
    imports = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if not isinstance(node, ast.ImportFrom):
            continue
        if node.module != "typing":
            continue
        for alias in node.names:
            if alias.name == "Any":
                imports.append(f"{path}:{node.lineno} imports typing.Any")
    return imports


def _legacy_record_string_key_access(path: Path) -> list[str]:
    record_names = {
        "block",
        "block_graph",
        "c",
        "child",
        "comments",
        "curr_block",
        "false_block",
        "graph",
        "section",
        "start_block",
        "true_block",
    }
    record_keys = {
        "block",
        "children",
        "code",
        "depth",
        "end_loc",
        "index",
        "loc",
        "parents",
        "section",
        "start_block",
    }
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if not isinstance(node, ast.Subscript):
            continue
        if not isinstance(node.slice, ast.Constant) or not isinstance(node.slice.value, str):
            continue
        if node.slice.value not in record_keys:
            continue
        root_name = _subscript_root_name(node.value)
        if root_name in record_names:
            violations.append(
                f"{path}:{node.lineno} use attribute access for {root_name}[{node.slice.value!r}]"
            )
    return violations


def _meta_block_dict_usage(path: Path) -> list[str]:
    meta_names = {
        "inner",
        "meta_block_graph",
        "node",
        "start_node",
        "true_node",
    }
    meta_keys = {
        "blocks",
        "cases",
        "cond",
        "conj",
        "false",
        "flag",
        "index",
        "inner",
        "loc",
        "meta_block_index",
        "next",
        "preface",
        "start_block",
        "true",
        "type",
    }
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if not isinstance(node, ast.Subscript):
            continue
        if not isinstance(node.slice, ast.Constant) or not isinstance(node.slice.value, str):
            continue
        if node.slice.value not in meta_keys:
            continue
        root_name = _subscript_root_name(node.value)
        if root_name in meta_names:
            violations.append(
                f"{path}:{node.lineno} use typed MetaBlock fields for {root_name}[{node.slice.value!r}]"
            )
    return violations


def _subscript_root_name(node: ast.AST) -> str | None:
    while isinstance(node, ast.Subscript):
        node = node.value
    if isinstance(node, ast.Name):
        return node.id
    return None


def _function_arguments(node: ast.FunctionDef | ast.AsyncFunctionDef) -> list[ast.arg]:
    args = list(node.args.posonlyargs)
    args.extend(node.args.args)
    args.extend(node.args.kwonlyargs)
    if node.args.vararg is not None:
        args.append(node.args.vararg)
    if node.args.kwarg is not None:
        args.append(node.args.kwarg)
    return args


if __name__ == "__main__":
    unittest.main()
