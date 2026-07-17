import unittest

from decomp.architectures import get_architecture, list_architectures


class ArchitectureRegistryTests(unittest.TestCase):
    def test_lists_current_and_prospective_targets(self) -> None:
        ids = {arch.id for arch in list_architectures()}

        self.assertIn("arm-thumb", ids)
        self.assertIn("m6800-6303", ids)
        self.assertIn("m6809e", ids)
        self.assertIn("sh3-dsp", ids)
        self.assertIn("xcore-xs1", ids)

    def test_current_arm_thumb_backend_is_supported(self) -> None:
        arch = get_architecture("arm-thumb")

        self.assertEqual(arch.status, "supported")
        self.assertEqual(arch.rasm2_arch, "arm.gnu")


if __name__ == "__main__":
    unittest.main()
