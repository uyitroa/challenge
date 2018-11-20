class Solution:
	def jump(self, nums):
		"""
		:type nums: List[int]
		:rtype: int
		"""
		current_end = 0
		n = len(nums)
		current_farthest = 0
		count = 0
		for x in range(n):
			if current_end >= n - 1:
				break
			if current_farthest < x + nums[x]:
				current_farthest = x + nums[x]
			if x == current_end:
				count += 1
				current_end = current_farthest

		return count


def test():
	solution = Solution()
	print(solution.jump([9, 2, 3, 4, 5, 6, 7, 8, 9]))


if __name__ == "__main__":
	test()
