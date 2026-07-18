import unittest

from decomp.legacy_types import LegacyBlock
from decomp.render_c import RenderedCondition, render_condition


class RenderCTests(unittest.TestCase):
    def test_render_condition_returns_named_render_record(self) -> None:
        address = 0x08020000
        block = LegacyBlock(
            address=address,
            end_address=0x08020002,
            instructions=(
                [b"0x8020000", b"2", b"0000", b"cbz", b"r0,", b"0x8020004"],
            ),
            successors=(0x08020004,),
            predecessors=(),
        )

        rendered = render_condition([address], [], [True], {address: block})

        self.assertIsInstance(rendered, RenderedCondition)
        self.assertIn(b"cond0 = r0 != 0;", rendered.setup)
        self.assertEqual(rendered.expression, b"cond0")


if __name__ == "__main__":
    unittest.main()
