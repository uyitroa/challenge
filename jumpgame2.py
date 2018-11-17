class Solution:
	def jump(self, nums):
		"""

		:param nums:
		:return:
		"""
		if len(nums) == 1:
			return 0
		current_index = 0
		count = 0
		for x in range(len(nums)):

		return count


def test():
	solution = Solution()
	print(solution.jump([2, 3, 6, 7, 1, 1, 3, 4, 5, 7, 8]))


if __name__ == "__main__":
	test()
