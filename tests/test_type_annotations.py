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
