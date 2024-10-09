import unittest
from L1_6 import test_procedure


class TestSum(unittest.TestCase):

    def test_minimum_size_corrupt_set(self):
        input_set = (22, 22)
        self.assertEqual(test_procedure(input_set), 1, "Should be 1")

    def test_minimum_size_valid_set(self):
        input_set = (22, 23)
        self.assertEqual(test_procedure(input_set), 0, "Should be 0")

    def test_foursize_corrupt_set(self):
        input_set = (22, 23, 22, 1)
        self.assertEqual(test_procedure(input_set), 0, "Should be 0")

    def test_foursize_valid_set(self):
        input_set = (1, 2, 2, 2)
        self.assertEqual(test_procedure(input_set), 1, "Should be 1")


if __name__ == "__main__":
    unittest.main()
