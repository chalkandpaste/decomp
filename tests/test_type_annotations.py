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

    def test_project_uses_explicit_imports(self) -> None:
        violations = []
        for root in (Path("src/decomp"), Path("tests")):
            for path in sorted(root.rglob("*.py")):
                violations.extend(_wildcard_imports(path))

        self.assertEqual(violations, [])

    def test_block_graph_does_not_keep_legacy_child_builders(self) -> None:
        self.assertEqual(
            _forbidden_defs(
                Path("src/decomp/block_graph.py"),
                {"get_children", "mk_block"},
            ),
            [],
        )

    def test_block_graph_stays_out_of_cli_behavior(self) -> None:
        block_graph_path = Path("src/decomp/block_graph.py")

        self.assertEqual(_module_import_violations(block_graph_path, {"argparse"}), [])
        self.assertEqual(_module_main_guard_violations(block_graph_path), [])

    def test_function_signatures_stays_out_of_cli_behavior(self) -> None:
        function_signatures_path = Path("src/decomp/function_signatures.py")

        self.assertEqual(_module_import_violations(function_signatures_path, {"argparse"}), [])
        self.assertEqual(_module_main_guard_violations(function_signatures_path), [])

    def test_function_signatures_stays_out_of_recursive_discovery(self) -> None:
        function_signatures_path = Path("src/decomp/function_signatures.py")

        self.assertEqual(_module_import_violations(function_signatures_path, {"block_graph"}), [])
        self.assertEqual(
            _forbidden_defs(
                function_signatures_path,
                {"discover_functions", "generate_func_sigs", "generate_set_of_funcs"},
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

    def test_graph_driven_modules_use_graph_relationship_methods(self) -> None:
        violations = []
        for path in (
            Path("src/decomp/block_graph.py"),
            Path("src/decomp/structure.py"),
        ):
            violations.extend(_legacy_block_relationship_field_access(path))

        self.assertEqual(violations, [])

    def test_cfg_post_processing_uses_control_flow_graph_methods(self) -> None:
        path = Path("src/decomp/analysis/cfg_builder.py")
        functions = {
            "_attach_incoming_edges",
            "_legacy_parent_index",
            "_reachable_block_order",
            "_trim_overlapping_blocks",
        }

        violations = []
        for function_name in functions:
            violations.extend(_raw_named_subscripts_in_function(path, function_name, {"blocks"}))
            violations.extend(_attribute_access_in_function(path, function_name, "cfg", {"blocks"}))

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

    def test_meta_block_driven_modules_use_graph_methods(self) -> None:
        violations = []
        for path in (
            Path("src/decomp/render_c.py"),
            Path("src/decomp/structure.py"),
        ):
            violations.extend(_attribute_access_violations(path, "meta_block_graph", {"meta_blocks"}))
            violations.extend(_attribute_access_violations(path, "graph", {"meta_blocks"}))

        self.assertEqual(violations, [])

    def test_meta_block_records_are_frozen_and_tuple_backed(self) -> None:
        record_names = {"EndBlock", "IfBlock", "LinearBlock", "MetaBlockGraph", "SwitchBlock", "WhileBlock"}
        path = Path("src/decomp/meta_blocks.py")

        self.assertEqual(_unfrozen_dataclass_records(path, record_names), [])
        self.assertEqual(_mutable_list_record_fields(path, record_names), [])

    def test_structure_uses_sets_for_membership_tracking(self) -> None:
        self.assertEqual(
            _empty_dict_assignments(
                Path("src/decomp/structure.py"),
                {"loops", "seen_locs", "seen_loops", "seen_loops2"},
            ),
            [],
        )

    def test_structure_constructs_tuple_backed_meta_blocks(self) -> None:
        self.assertEqual(
            _mutable_meta_block_constructor_arguments(Path("src/decomp/structure.py")),
            [],
        )

    def test_structure_uses_explicit_control_flow_instead_of_bare_except(self) -> None:
        self.assertEqual(_bare_except_handlers(Path("src/decomp/structure.py")), [])

    def test_structure_uses_fifo_collections_for_fifo_traversal(self) -> None:
        self.assertEqual(_list_pop_zero_calls(Path("src/decomp/structure.py")), [])

    def test_loop_tracker_uses_explicit_membership_and_fifo_collections(self) -> None:
        path = Path("src/decomp/loop_tracker.py")

        self.assertEqual(_list_pop_zero_calls(path), [])
        self.assertEqual(
            _forbidden_attribute_annotations(
                path,
                {
                    "not_loop_loc": {"dict"},
                },
            ),
            [],
        )

    def test_loop_tracker_uses_loop_info_record_for_cached_loop_state(self) -> None:
        path = Path("src/decomp/loop_tracker.py")

        self.assertEqual(_unfrozen_dataclass_records(path, {"LoopInfo"}), [])
        self.assertEqual(_forbidden_attribute_names(path, {"loc_to_loop_end", "loc_to_loop_locs", "loc_to_loop_start"}), [])
        self.assertEqual(_external_attribute_access(Path("tests/test_loop_tracker.py"), {"_loc_to_loop"}), [])

    def test_loop_tracker_loop_accessors_do_not_keep_dead_branches(self) -> None:
        self.assertEqual(
            _statements_after_return_in_functions(
                Path("src/decomp/loop_tracker.py"),
                {"get_loop_end", "get_loop_start"},
            ),
            [],
        )

    def test_add_function_sigs_uses_legacy_instruction_accessors(self) -> None:
        self.assertEqual(
            _exact_import_violations(
                Path("src/decomp/function_signatures.py"),
                {"decomp.instructions"},
            ),
            [],
        )
        self.assertEqual(
            _raw_numeric_subscripts_in_function(
                Path("src/decomp/function_signatures.py"),
                "add_function_sigs",
                {3, 4},
            ),
            [],
        )
        self.assertEqual(
            _function_call_violations(
                Path("src/decomp/function_signatures.py"),
                "add_function_sigs",
                {"successors"},
            ),
            [],
        )
        self.assertEqual(
            _function_call_violations(
                Path("src/decomp/function_signatures.py"),
                "add_function_sigs",
                {"mnemonic", "operand_int"},
            ),
            [],
        )

    def test_get_function_signature_uses_register_effect_model(self) -> None:
        self.assertEqual(
            _import_prefix_violations(
                Path("src/decomp/function_signatures.py"),
                {"decomp.arch.arm_thumb"},
            ),
            [],
        )
        self.assertEqual(
            _function_call_violations(
                Path("src/decomp/function_signatures.py"),
                "get_function_signature",
                {"crs"},
            ),
            [],
        )
        self.assertEqual(
            _direct_name_call_violations(
                Path("src/decomp/function_signatures.py"),
                "_register_effect_for_instruction",
                {"register_effect"},
            ),
            [],
        )

    def test_signature_callers_use_named_signature_fields(self) -> None:
        self.assertEqual(
            _raw_numeric_subscripts_in_function(
                Path("src/decomp/render_c.py"),
                "generate_func_decl",
                {0, 1},
            ),
            [],
        )
        self.assertEqual(
            _raw_numeric_subscripts_in_function(
                Path("src/decomp/function_discovery.py"),
                "generate_func_sigs",
                {0, 1},
            ),
            [],
        )

    def test_signature_callers_use_shared_declaration_renderer(self) -> None:
        self.assertEqual(
            _attribute_access_violations(
                Path("src/decomp/render_c.py"),
                "signature",
                {"argument_scope", "return_scope"},
            ),
            [],
        )
        self.assertEqual(
            _attribute_access_violations(
                Path("src/decomp/function_discovery.py"),
                "signature",
                {"argument_scope", "return_scope"},
            ),
            [],
        )

    def test_function_declarations_use_register_scope_methods(self) -> None:
        self.assertEqual(
            _raw_attribute_subscripts_in_function(
                Path("src/decomp/function_signatures.py"),
                "render_function_declaration",
                {"argument_scope", "return_scope"},
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

    def test_cfg_child_discovery_uses_typed_flow_info(self) -> None:
        self.assertEqual(
            _function_call_violations(
                Path("src/decomp/analysis/cfg_builder.py"),
                "_children_for_block",
                {"_legacy_tokens"},
            ),
            [],
        )
        self.assertEqual(
            _flow_attribute_access_in_function(
                Path("src/decomp/analysis/cfg_builder.py"),
                "_children_for_block",
                {"kind", "targets", "fallthrough", "is_function_exit"},
            ),
            [],
        )

    def test_shared_analysis_uses_architecture_behavior_protocol(self) -> None:
        violations = []
        for path in (
            Path("src/decomp/analysis/cfg_builder.py"),
            Path("src/decomp/analysis/xrefs.py"),
            Path("src/decomp/legacy_adapter.py"),
        ):
            violations.extend(_import_prefix_violations(path, {"decomp.arch.arm_thumb"}))

        self.assertEqual(violations, [])

    def test_instruction_buffer_uses_architecture_backend_protocol(self) -> None:
        self.assertEqual(
            _imported_name_violations(
                Path("src/decomp/instruction_buffer.py"),
                {
                    "ArmThumbBackend",
                    "fix_jump_offset",
                    "is_probable_address_literal",
                    "normalize_rasm2_output",
                    "twos_complement",
                },
            ),
            [],
        )

    def test_cfg_block_collection_uses_typed_return_predicates(self) -> None:
        self.assertEqual(
            _exact_import_violations(
                Path("src/decomp/analysis/cfg_builder.py"),
                {"decomp.instructions"},
            ),
            [],
        )
        self.assertEqual(
            _forbidden_defs(
                Path("src/decomp/analysis/cfg_builder.py"),
                {"_mnemonic"},
            ),
            [],
        )
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
            _exact_import_violations(
                Path("src/decomp/analysis/xrefs.py"),
                {"decomp.instructions"},
            ),
            [],
        )
        self.assertEqual(
            _forbidden_defs(
                Path("src/decomp/analysis/xrefs.py"),
                {"_mnemonic"},
            ),
            [],
        )
        self.assertEqual(
            _function_call_violations(
                Path("src/decomp/analysis/xrefs.py"),
                "_collect_block_references",
                {"_legacy_tokens"},
            ),
            [],
        )
        self.assertEqual(
            _flow_attribute_access_in_function(
                Path("src/decomp/analysis/xrefs.py"),
                "_collect_block_references",
                {"targets"},
            ),
            [],
        )
        self.assertEqual(
            _flow_attribute_access_in_function(
                Path("src/decomp/analysis/xrefs.py"),
                "_tail_branches_after_restore",
                {"targets"},
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

    def test_xrefs_use_control_flow_graph_methods(self) -> None:
        self.assertEqual(
            _attribute_access_violations(
                Path("src/decomp/analysis/xrefs.py"),
                "cfg",
                {"blocks"},
            ),
            [],
        )

    def test_parity_uses_control_flow_graph_methods(self) -> None:
        self.assertEqual(
            _attribute_access_violations(
                Path("src/decomp/parity.py"),
                "cfg",
                {"blocks"},
            ),
            [],
        )

    def test_thumb_address_normalization_stays_in_arch_helper(self) -> None:
        violations = []
        helper_path = Path("src/decomp/arch/arm_thumb/addresses.py")
        for path in sorted(Path("src/decomp").rglob("*.py")):
            if path == helper_path:
                continue
            violations.extend(_inline_thumb_address_mask_violations(path))

        self.assertEqual(violations, [])

    def test_render_c_condition_logic_uses_legacy_instruction_accessors(self) -> None:
        self.assertEqual(
            _raw_numeric_subscripts_in_function(
                Path("src/decomp/render_c.py"),
                "render_condition",
                {3, 4, 5},
            ),
            [],
        )
        self.assertEqual(
            _raw_numeric_subscripts_in_function(
                Path("src/decomp/render_c.py"),
                "generate_func_cf_from_graph",
                {3, 4, 5},
            ),
            [],
        )

    def test_convert_c_dispatch_uses_named_instruction_accessors(self) -> None:
        self.assertEqual(
            _raw_numeric_subscripts_in_function(
                Path("src/decomp/convert_c.py"),
                "convert_instruction",
                {0},
            ),
            [],
        )

    def test_convert_c_binary_ops_use_named_instruction_accessors(self) -> None:
        self.assertEqual(
            _raw_numeric_subscripts_in_function(
                Path("src/decomp/convert_c.py"),
                "binop",
                {0, 1, 2, 3, 4, 5},
            ),
            [],
        )

    def test_convert_c_simple_renderers_use_named_instruction_accessors(self) -> None:
        violations = []
        for function_name in {"div", "mov", "mul", "n_mov", "rev_sub", "sxtab", "vmlas"}:
            violations.extend(
                _raw_numeric_subscripts_in_function(
                    Path("src/decomp/convert_c.py"),
                    function_name,
                    {1, 2, 3},
                )
            )
            violations.extend(
                _negative_subscripts_in_function(
                    Path("src/decomp/convert_c.py"),
                    function_name,
                )
            )

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


def _wildcard_imports(path: Path) -> list[str]:
    imports = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if not isinstance(node, ast.ImportFrom):
            continue
        if any(alias.name == "*" for alias in node.names):
            imports.append(f"{path}:{node.lineno} avoid wildcard imports")
    return imports


def _module_import_violations(path: Path, modules: set[str]) -> list[str]:
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if isinstance(node, ast.Import):
            for alias in node.names:
                if alias.name.split(".", 1)[0] in modules:
                    violations.append(f"{path}:{node.lineno} keep {alias.name} in CLI modules")
        if isinstance(node, ast.ImportFrom) and node.module is not None:
            if node.module.split(".", 1)[0] in modules:
                violations.append(f"{path}:{node.lineno} keep {node.module} in CLI modules")
    return violations


def _exact_import_violations(path: Path, modules: set[str]) -> list[str]:
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if isinstance(node, ast.Import):
            for alias in node.names:
                if alias.name in modules:
                    violations.append(f"{path}:{node.lineno} keep {alias.name} behind a typed helper")
        if isinstance(node, ast.ImportFrom) and node.module in modules:
            violations.append(f"{path}:{node.lineno} keep {node.module} behind a typed helper")
    return violations


def _imported_name_violations(path: Path, names: set[str]) -> list[str]:
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if isinstance(node, ast.Import):
            for alias in node.names:
                if alias.name.rsplit(".", 1)[-1] in names or alias.asname in names:
                    violations.append(f"{path}:{node.lineno} depend on architecture backend protocol")
        if isinstance(node, ast.ImportFrom):
            for alias in node.names:
                if alias.name in names or alias.asname in names:
                    violations.append(f"{path}:{node.lineno} depend on architecture backend protocol")
    return violations


def _import_prefix_violations(path: Path, prefixes: set[str]) -> list[str]:
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if isinstance(node, ast.Import):
            for alias in node.names:
                if any(alias.name == prefix or alias.name.startswith(f"{prefix}.") for prefix in prefixes):
                    violations.append(f"{path}:{node.lineno} depend on architecture behavior protocol")
        if isinstance(node, ast.ImportFrom) and node.module is not None:
            if any(node.module == prefix or node.module.startswith(f"{prefix}.") for prefix in prefixes):
                violations.append(f"{path}:{node.lineno} depend on architecture behavior protocol")
    return violations


def _module_main_guard_violations(path: Path) -> list[str]:
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if isinstance(node, ast.If) and _is_main_guard(node):
            violations.append(f"{path}:{node.lineno} keep __main__ entrypoints in CLI modules")
    return violations


def _is_main_guard(node: ast.If) -> bool:
    test = node.test
    if not isinstance(test, ast.Compare):
        return False
    if len(test.ops) != 1 or not isinstance(test.ops[0], ast.Eq):
        return False
    if len(test.comparators) != 1:
        return False
    return (
        _is_name_constant_pair(test.left, test.comparators[0], "__name__", "__main__")
        or _is_name_constant_pair(test.comparators[0], test.left, "__name__", "__main__")
    )


def _is_name_constant_pair(left: ast.AST, right: ast.AST, name: str, value: str) -> bool:
    return (
        isinstance(left, ast.Name)
        and left.id == name
        and isinstance(right, ast.Constant)
        and right.value == value
    )


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


def _legacy_block_relationship_field_access(path: Path) -> list[str]:
    relationship_fields = {"successors", "predecessors"}
    block_names = {"block", "child", "children", "curr_block"}
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if not isinstance(node, ast.Attribute) or node.attr not in relationship_fields:
            continue
        if _attribute_root_name(node.value) in block_names:
            violations.append(f"{path}:{node.lineno} use graph.{node.attr}(address)")
    return violations


def _attribute_access_violations(path: Path, root_name: str, attribute_names: set[str]) -> list[str]:
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if not isinstance(node, ast.Attribute) or node.attr not in attribute_names:
            continue
        if _attribute_root_name(node.value) == root_name:
            violations.append(f"{path}:{node.lineno} use {root_name} methods instead of {root_name}.{node.attr}")
    return violations


def _attribute_access_in_function(
    path: Path,
    function_name: str,
    root_name: str,
    attribute_names: set[str],
) -> list[str]:
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if not isinstance(node, ast.FunctionDef) or node.name != function_name:
            continue
        for child in ast.walk(node):
            if not isinstance(child, ast.Attribute) or child.attr not in attribute_names:
                continue
            if _attribute_root_name(child.value) == root_name:
                violations.append(
                    f"{path}:{child.lineno} {function_name} should use {root_name} methods instead of {root_name}.{child.attr}"
                )
    return violations


def _flow_attribute_access_in_function(
    path: Path,
    function_name: str,
    attribute_names: set[str],
) -> list[str]:
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if not isinstance(node, ast.FunctionDef) or node.name != function_name:
            continue
        for child in ast.walk(node):
            if not isinstance(child, ast.Attribute) or child.attr not in attribute_names:
                continue
            if _attribute_root_name(child.value) == "flow" or _attribute_chain_contains(child.value, "flow"):
                violations.append(
                    f"{path}:{child.lineno} {function_name} should use FlowInfo methods instead of flow.{child.attr}"
                )
    return violations


def _attribute_chain_contains(node: ast.AST, attribute_name: str) -> bool:
    while isinstance(node, ast.Attribute):
        if node.attr == attribute_name:
            return True
        node = node.value
    return False


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


def _unfrozen_dataclass_records(path: Path, names: set[str]) -> list[str]:
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if not isinstance(node, ast.ClassDef) or node.name not in names:
            continue
        if not _has_frozen_dataclass_decorator(node):
            violations.append(f"{path}:{node.lineno} {node.name} should be a frozen dataclass")
    return violations


def _has_frozen_dataclass_decorator(node: ast.ClassDef) -> bool:
    for decorator in node.decorator_list:
        if not isinstance(decorator, ast.Call):
            continue
        if _call_name(decorator.func) != "dataclass":
            continue
        for keyword in decorator.keywords:
            if keyword.arg == "frozen" and isinstance(keyword.value, ast.Constant) and keyword.value.value is True:
                return True
    return False


def _mutable_list_record_fields(path: Path, names: set[str]) -> list[str]:
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if not isinstance(node, ast.ClassDef) or node.name not in names:
            continue
        for item in node.body:
            if not isinstance(item, ast.AnnAssign):
                continue
            if _annotation_uses_list(item.annotation):
                violations.append(f"{path}:{item.lineno} {node.name} fields should use tuple-backed values")
    return violations


def _annotation_uses_list(node: ast.AST) -> bool:
    if isinstance(node, ast.Name):
        return node.id == "list"
    if isinstance(node, ast.Attribute):
        return node.attr == "List"
    if isinstance(node, ast.Subscript):
        return _annotation_uses_list(node.value)
    if isinstance(node, ast.BinOp):
        return _annotation_uses_list(node.left) or _annotation_uses_list(node.right)
    return False


def _empty_dict_assignments(path: Path, names: set[str]) -> list[str]:
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if isinstance(node, ast.Assign):
            if not _is_empty_dict(node.value):
                continue
            for target in node.targets:
                if isinstance(target, ast.Name) and target.id in names:
                    violations.append(f"{path}:{node.lineno} use set() for membership tracking")
        elif isinstance(node, ast.AnnAssign):
            if isinstance(node.target, ast.Name) and node.target.id in names and _is_empty_dict(node.value):
                violations.append(f"{path}:{node.lineno} use set() for membership tracking")
    return violations


def _is_empty_dict(node: ast.AST | None) -> bool:
    return isinstance(node, ast.Dict) and len(node.keys) == 0 and len(node.values) == 0


def _mutable_meta_block_constructor_arguments(path: Path) -> list[str]:
    record_keyword_names = {
        "IfBlock": {"condition_blocks", "conjunctions", "flags"},
        "LinearBlock": {"block_addresses"},
        "SwitchBlock": {"cases", "preface"},
        "EndBlock": {"block_addresses"},
    }
    list_variable_names = {"children_locs", "preface"}
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if not isinstance(node, ast.Call):
            continue
        call_name = _call_name(node.func)
        keyword_names = record_keyword_names.get(call_name)
        if keyword_names is None:
            continue
        for keyword in node.keywords:
            if keyword.arg not in keyword_names:
                continue
            if isinstance(keyword.value, ast.List):
                violations.append(f"{path}:{node.lineno} pass tuple-backed values to {call_name}.{keyword.arg}")
            elif isinstance(keyword.value, ast.Name) and keyword.value.id in list_variable_names:
                violations.append(f"{path}:{node.lineno} wrap {keyword.value.id} before {call_name}.{keyword.arg}")
    return violations


def _bare_except_handlers(path: Path) -> list[str]:
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if isinstance(node, ast.ExceptHandler) and node.type is None:
            violations.append(f"{path}:{node.lineno} replace bare except with explicit control flow or exception type")
    return violations


def _list_pop_zero_calls(path: Path) -> list[str]:
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if not isinstance(node, ast.Call):
            continue
        if not isinstance(node.func, ast.Attribute) or node.func.attr != "pop":
            continue
        if len(node.args) != 1:
            continue
        argument = node.args[0]
        if isinstance(argument, ast.Constant) and argument.value == 0:
            violations.append(f"{path}:{node.lineno} use deque.popleft() for FIFO traversal")
    return violations


def _forbidden_attribute_annotations(path: Path, names_to_forbidden_types: dict[str, set[str]]) -> list[str]:
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if not isinstance(node, ast.AnnAssign):
            continue
        if not isinstance(node.target, ast.Attribute):
            continue
        forbidden_types = names_to_forbidden_types.get(node.target.attr)
        if forbidden_types is None:
            continue
        for forbidden_type in forbidden_types:
            if _annotation_mentions_name(node.annotation, forbidden_type):
                violations.append(f"{path}:{node.lineno} {node.target.attr} should not use {forbidden_type}")
    return violations


def _forbidden_attribute_names(path: Path, names: set[str]) -> list[str]:
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if isinstance(node, ast.Attribute) and node.attr in names:
            violations.append(f"{path}:{node.lineno} use LoopInfo cache instead of {node.attr}")
    return violations


def _external_attribute_access(path: Path, names: set[str]) -> list[str]:
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if isinstance(node, ast.Attribute) and node.attr in names:
            violations.append(f"{path}:{node.lineno} use public model accessors instead of {node.attr}")
    return violations


def _annotation_mentions_name(node: ast.AST, name: str) -> bool:
    if isinstance(node, ast.Name):
        return node.id == name
    if isinstance(node, ast.Attribute):
        return node.attr == name
    if isinstance(node, ast.Subscript):
        return _annotation_mentions_name(node.value, name) or _annotation_mentions_name(node.slice, name)
    if isinstance(node, ast.Tuple):
        return any(_annotation_mentions_name(element, name) for element in node.elts)
    if isinstance(node, ast.BinOp):
        return _annotation_mentions_name(node.left, name) or _annotation_mentions_name(node.right, name)
    return False


def _statements_after_return_in_functions(path: Path, function_names: set[str]) -> list[str]:
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if not isinstance(node, ast.FunctionDef) or node.name not in function_names:
            continue
        violations.extend(_statements_after_return(path, node.body, node.name))
    return violations


def _statements_after_return(path: Path, statements: list[ast.stmt], function_name: str) -> list[str]:
    violations = []
    saw_return = False
    for statement in statements:
        if saw_return:
            violations.append(f"{path}:{statement.lineno} {function_name} has unreachable code after return")
        if isinstance(statement, ast.Return):
            saw_return = True
        elif isinstance(statement, ast.If):
            violations.extend(_statements_after_return(path, statement.body, function_name))
            violations.extend(_statements_after_return(path, statement.orelse, function_name))
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


def _negative_subscripts_in_function(path: Path, function_name: str) -> list[str]:
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if not isinstance(node, ast.FunctionDef) or node.name != function_name:
            continue
        for child in ast.walk(node):
            if not isinstance(child, ast.Subscript):
                continue
            if _is_negative_int_constant(child.slice):
                violations.append(f"{path}:{child.lineno} {function_name} should use named operand helpers")
    return violations


def _is_negative_int_constant(node: ast.AST) -> bool:
    return (
        isinstance(node, ast.UnaryOp)
        and isinstance(node.op, ast.USub)
        and isinstance(node.operand, ast.Constant)
        and isinstance(node.operand.value, int)
    )


def _raw_attribute_subscripts_in_function(path: Path, function_name: str, attribute_names: set[str]) -> list[str]:
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if not isinstance(node, ast.FunctionDef) or node.name != function_name:
            continue
        for child in ast.walk(node):
            if not isinstance(child, ast.Subscript):
                continue
            if isinstance(child.value, ast.Attribute) and child.value.attr in attribute_names:
                violations.append(f"{path}:{child.lineno} {function_name} should use scope methods")
    return violations


def _raw_named_subscripts_in_function(path: Path, function_name: str, root_names: set[str]) -> list[str]:
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if not isinstance(node, ast.FunctionDef) or node.name != function_name:
            continue
        for child in ast.walk(node):
            if not isinstance(child, ast.Subscript):
                continue
            root_name = _subscript_root_name(child.value)
            if root_name in root_names:
                violations.append(f"{path}:{child.lineno} {function_name} should use graph methods instead of {root_name}[...]")
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


def _direct_name_call_violations(path: Path, function_name: str, names: set[str]) -> list[str]:
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if not isinstance(node, ast.FunctionDef) or node.name != function_name:
            continue
        for child in ast.walk(node):
            if not isinstance(child, ast.Call):
                continue
            if isinstance(child.func, ast.Name) and child.func.id in names:
                violations.append(f"{path}:{child.lineno} {function_name} should call through behavior")
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


def _inline_thumb_address_mask_violations(path: Path) -> list[str]:
    violations = []
    tree = ast.parse(path.read_text(), filename=str(path))
    for node in ast.walk(tree):
        if not isinstance(node, ast.BinOp) or not isinstance(node.op, ast.BitAnd):
            continue
        if _is_bitwise_not_one(node.left) or _is_bitwise_not_one(node.right):
            violations.append(f"{path}:{node.lineno} use normalize_interworking_address()")
    return violations


def _is_bitwise_not_one(node: ast.AST) -> bool:
    return (
        isinstance(node, ast.UnaryOp)
        and isinstance(node.op, ast.Invert)
        and isinstance(node.operand, ast.Constant)
        and node.operand.value == 1
    )


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


def _attribute_root_name(node: ast.AST) -> str | None:
    while isinstance(node, ast.Attribute):
        node = node.value
    return _subscript_root_name(node)


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
