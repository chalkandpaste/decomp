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

    def test_legacy_records_do_not_expose_mapping_protocol(self) -> None:
        self.assertEqual(
            _forbidden_methods(
                Path("src/decomp/legacy_types.py"),
                {"__getitem__", "__contains__", "get"},
            ),
            [],
        )

    def test_legacy_records_do_not_expose_old_field_aliases(self) -> None:
        self.assertEqual(
            _forbidden_properties(
                Path("src/decomp/legacy_types.py"),
                {"block", "children", "end_loc", "index", "loc", "parents", "start_block"},
            ),
            [],
        )

    def test_meta_blocks_use_typed_records(self) -> None:
        violations = []
        for root in (Path("src/decomp"), Path("tests")):
            for path in sorted(root.rglob("*.py")):
                violations.extend(_meta_block_dict_usage(path))

        self.assertEqual(violations, [])

    def test_structure_recovery_stays_out_of_disassemble_module(self) -> None:
        disassemble_path = Path("src/decomp/disassemble.py")

        self.assertEqual(_forbidden_defs(disassemble_path, {"MetaBlockFinder", "annotate_graph", "simplify_if"}), [])

    def test_rendering_stays_out_of_disassemble_module(self) -> None:
        disassemble_path = Path("src/decomp/disassemble.py")

        self.assertEqual(
            _forbidden_defs(
                disassemble_path,
                {"print_block", "print_if_cond", "generate_func_cf_from_graph", "generate_func_decl"},
            ),
            [],
        )

    def test_assembly_rendering_stays_out_of_block_graph_module(self) -> None:
        self.assertEqual(
            _forbidden_defs(
                Path("src/decomp/block_graph.py"),
                {"generate_asm", "print_block_graph", "render_block_graph_asm"},
            ),
            [],
        )

    def test_graph_driven_modules_do_not_index_raw_block_maps(self) -> None:
        violations = []
        for path in (
            Path("src/decomp/block_graph.py"),
            Path("src/decomp/function_signatures.py"),
            Path("src/decomp/legacy_adapter.py"),
            Path("src/decomp/render_c.py"),
            Path("src/decomp/structure.py"),
        ):
            violations.extend(_raw_block_index_access(path))

        self.assertEqual(violations, [])

    def test_graph_driven_modules_do_not_read_raw_block_storage(self) -> None:
        violations = []
        for path in (
            Path("src/decomp/block_graph.py"),
            Path("src/decomp/function_signatures.py"),
            Path("src/decomp/legacy_adapter.py"),
            Path("src/decomp/render_c.py"),
            Path("src/decomp/structure.py"),
        ):
            violations.extend(_raw_graph_storage_access(path))

        self.assertEqual(violations, [])

    def test_meta_block_graph_construction_uses_source_blocks_name(self) -> None:
        violations = []
        for root in (Path("src/decomp"), Path("tests")):
            for path in sorted(root.rglob("*.py")):
                violations.extend(_legacy_meta_block_graph_constructor_keywords(path))

        self.assertEqual(violations, [])

    def test_meta_block_graph_uses_source_blocks_name(self) -> None:
        violations = []
        for root in (Path("src/decomp"), Path("tests")):
            for path in sorted(root.rglob("*.py")):
                violations.extend(_legacy_meta_block_graph_block_index_access(path))

        self.assertEqual(violations, [])

    def test_add_function_sigs_uses_legacy_instruction_accessors(self) -> None:
        self.assertEqual(
            _raw_numeric_subscripts_in_function(
                Path("src/decomp/function_signatures.py"),
                "add_function_sigs",
                {3, 4},
            ),
            [],
        )

    def test_get_function_signature_uses_register_effect_model(self) -> None:
        self.assertEqual(
            _function_call_violations(
                Path("src/decomp/function_signatures.py"),
                "get_function_signature",
                {"crs"},
            ),
            [],
        )

    def test_typed_function_signature_traversal_stays_off_legacy_decode(self) -> None:
        self.assertEqual(
            _function_call_violations(
                Path("src/decomp/function_signatures.py"),
                "_get_function_signature_from_cfg",
                {"decode_legacy_tokens", "legacy_block_graph_to_cfg"},
            ),
            [],
        )

    def test_function_signature_wrapper_uses_typed_loop_tracker(self) -> None:
        self.assertEqual(
            _call_argument_name_violations(
                Path("src/decomp/function_signatures.py"),
                "get_function_signature",
                "LoopTracker",
                {"block_graph"},
            ),
            [],
        )

    def test_get_children_uses_legacy_instruction_accessors(self) -> None:
        self.assertEqual(
            _raw_numeric_subscripts_in_function(
                Path("src/decomp/block_graph.py"),
                "get_children",
                {0, 1, 3, 4, 5},
            ),
            [],
        )

    def test_cfg_child_discovery_uses_typed_flow_info(self) -> None:
        self.assertEqual(
            _function_call_violations(
                Path("src/decomp/analysis/cfg_builder.py"),
                "_children_for_block",
                {"_legacy_tokens"},
            ),
            [],
        )

    def test_cfg_block_collection_uses_typed_return_predicates(self) -> None:
        self.assertEqual(
            _function_call_violations(
                Path("src/decomp/analysis/cfg_builder.py"),
                "_collect_block_instructions",
                {"_contains_lr_restore", "_contains_pc_return", "_legacy_tokens"},
            ),
            [],
        )

    def test_xrefs_use_typed_flow_and_operands(self) -> None:
        self.assertEqual(
            _function_call_violations(
                Path("src/decomp/analysis/xrefs.py"),
                "_collect_block_references",
                {"_legacy_tokens"},
            ),
            [],
        )
        self.assertEqual(
            _function_call_violations(
                Path("src/decomp/analysis/xrefs.py"),
                "_tail_branches_after_restore",
                {"_legacy_tokens"},
            ),
            [],
        )
        self.assertEqual(
            _function_call_violations(
                Path("src/decomp/analysis/xrefs.py"),
                "_literal_loaded_into_register",
                {"_legacy_tokens"},
            ),
            [],
        )


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


def _forbidden_defs(path: Path, names: set[str]) -> list[str]:
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if not isinstance(node, ast.ClassDef | ast.FunctionDef | ast.AsyncFunctionDef):
            continue
        if node.name in names:
            violations.append(f"{path}:{node.lineno} {node.name} belongs in a focused module")
    return violations


def _forbidden_methods(path: Path, names: set[str]) -> list[str]:
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if not isinstance(node, ast.ClassDef):
            continue
        for item in node.body:
            if isinstance(item, ast.FunctionDef) and item.name in names:
                violations.append(f"{path}:{item.lineno} {node.name}.{item.name} is a retired compatibility shim")
    return violations


def _forbidden_properties(path: Path, names: set[str]) -> list[str]:
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if not isinstance(node, ast.ClassDef):
            continue
        for item in node.body:
            if not isinstance(item, ast.FunctionDef):
                continue
            has_property_decorator = any(
                isinstance(decorator, ast.Name) and decorator.id == "property"
                for decorator in item.decorator_list
            )
            if has_property_decorator and item.name in names:
                violations.append(f"{path}:{item.lineno} {node.name}.{item.name} is a retired field alias")
    return violations


def _raw_block_index_access(path: Path) -> list[str]:
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if not isinstance(node, ast.Subscript):
            continue
        if _subscript_root_name(node.value) == "block_index":
            violations.append(f"{path}:{node.lineno} use LegacyBlockGraph methods instead of block_index[...]")
    return violations


def _raw_graph_storage_access(path: Path) -> list[str]:
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if not isinstance(node, ast.Attribute):
            continue
        if node.attr != "blocks":
            continue
        if isinstance(node.value, ast.Name) and node.value.id == "block_graph":
            violations.append(f"{path}:{node.lineno} use LegacyBlockGraph methods instead of block_graph.blocks")
    return violations


def _legacy_meta_block_graph_constructor_keywords(path: Path) -> list[str]:
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if not isinstance(node, ast.Call):
            continue
        if not isinstance(node.func, ast.Name) or node.func.id != "MetaBlockGraph":
            continue
        for keyword in node.keywords:
            if keyword.arg == "block_index":
                violations.append(f"{path}:{node.lineno} construct MetaBlockGraph with source_blocks=")
    return violations


def _legacy_meta_block_graph_block_index_access(path: Path) -> list[str]:
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if not isinstance(node, ast.Attribute):
            continue
        if node.attr == "block_index":
            violations.append(f"{path}:{node.lineno} use MetaBlockGraph.source_blocks")
    return violations


def _raw_numeric_subscripts_in_function(path: Path, function_name: str, indexes: set[int]) -> list[str]:
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if not isinstance(node, ast.FunctionDef) or node.name != function_name:
            continue
        for child in ast.walk(node):
            if not isinstance(child, ast.Subscript):
                continue
            if not isinstance(child.slice, ast.Constant) or not isinstance(child.slice.value, int):
                continue
            if child.slice.value in indexes:
                violations.append(f"{path}:{child.lineno} {function_name} should use legacy_instruction accessors")
    return violations


def _function_call_violations(path: Path, function_name: str, names: set[str]) -> list[str]:
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if not isinstance(node, ast.FunctionDef) or node.name != function_name:
            continue
        for child in ast.walk(node):
            if not isinstance(child, ast.Call):
                continue
            name = _call_name(child.func)
            if name in names:
                violations.append(f"{path}:{child.lineno} {function_name} should not call {name}")
    return violations


def _call_argument_name_violations(
    path: Path,
    function_name: str,
    call_name: str,
    argument_names: set[str],
) -> list[str]:
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if not isinstance(node, ast.FunctionDef) or node.name != function_name:
            continue
        for child in ast.walk(node):
            if not isinstance(child, ast.Call):
                continue
            if _call_name(child.func) != call_name:
                continue
            for argument in child.args:
                if isinstance(argument, ast.Name) and argument.id in argument_names:
                    violations.append(f"{path}:{child.lineno} {function_name} should not pass {argument.id} to {call_name}")
    return violations


def _call_name(node: ast.AST) -> str | None:
    if isinstance(node, ast.Name):
        return node.id
    if isinstance(node, ast.Attribute):
        return node.attr
    return None


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
