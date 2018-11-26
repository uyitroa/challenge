import unittest
from money_distribute import Solution


class Test(unittest.TestCase):
	def test(self):
		solution = Solution()
		self.assertEqual(solution.distribute([1, 5, 10], 15), 2)
		self.assertEqual(solution.distribute([1, 7, 10], 15), 3)
		self.assertEqual(solution.distribute([1, 7, 10], 45), 6)
		self.assertEqual(solution.distribute([1, 4, 10], 45), 6)
		self.assertEqual(solution.distribute([1, 2, 8, 11, 12], 25), 3)
		self.assertEqual(solution.distribute([1, 11, 12], 134), 12)
		self.assertEqual(solution.distribute([1, 5, 10], 134), 17)
		self.assertEqual(solution.distribute([1, 8, 10], 64), 7)
		self.assertEqual(solution.distribute([1, 8, 10], 144), 15)
		self.assertEqual(solution.distribute([1, 2, 5, 10, 20, 50, 100, 200, 500], 123456789), 246920)
		self.assertEqual(solution.distribute([1, 2, 3, 4, 5, 6, 7, 8, 9, 15, 20, 99, 123, 456, 533, 534], 123456789), 231193)
