import unittest

from decomp.function_signatures import collect_functions


class CollectFunctionsTests(unittest.TestCase):
    def test_collects_literal_loaded_indirect_calls(self):
        block = {
            "loc": 0x080202CC,
            "children": [],
            "block": [
                [b"0x80202cc", b"2", b"0948", b"mov", b"r0,", b"0x8034f49"],
                [b"0x80202ce", b"2", b"8047", b"blx", b"r0"],
                [b"0x80202d0", b"2", b"0948", b"mov", b"r0,", b"0x8020189"],
                [b"0x80202d2", b"2", b"0047", b"bx", b"r0"],
            ],
        }
        graph = {"start_block": block, "index": {block["loc"]: block}}

        self.assertEqual(
            sorted(collect_functions(graph)),
            [0x08020188, 0x08034F48],
        )

    def test_collects_lower_address_unconditional_tail_branch(self):
        block = {
            "loc": 0x08034F48,
            "children": [0x0803228C],
            "block": [
                [b"0x8034f7e", b"2", b"0160", b"str", b"r1,", b"[r0,", b"0]"],
                [b"0x8034f80", b"4", b"fdf784b9", b"b.w", b"0x803228c"],
            ],
        }
        child = {"loc": 0x0803228C, "children": [], "block": []}
        graph = {
            "start_block": block,
            "index": {
                block["loc"]: block,
                child["loc"]: child,
            },
        }

        self.assertEqual(collect_functions(graph), [0x0803228C])


if __name__ == "__main__":
    unittest.main()
