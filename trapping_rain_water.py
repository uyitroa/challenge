class Solution:
	def trap(self, height):
		"""
		:param height: list[int]
		:return:
		"""
		last_width = -1
		max_wall = 0
		max_wall_index = 0
		maximum_local = []
		for index, width in enumerate(height):
			next_width = height[index + 1] if index + 1 != len(height) else -1
			if width > last_width and next_width <= width:
				if width >= max_wall:
					maximum_local = maximum_local[:max_wall_index]
					max_wall = width
					max_wall_index += 1
				else:
					while width > height[maximum_local[-1]]:
						maximum_local = maximum_local[:-1]

				maximum_local.append(index)
			last_width = width

		result = 0
		for x in range(len(maximum_local) - 1):
			start = maximum_local[x]
			end = maximum_local[x + 1]
			obstacle = 0
			smallest_wall = min(height[start], height[end])
			for y in range(start + 1, end):
				obstacle += min(height[y], smallest_wall)
			result += smallest_wall * (end - start - 1) - obstacle
		return result


def test():
	solution = Solution()
	print(solution.trap([1, 9, 7, 1, 3, 6, 4, 7, 4, 8, 3, 6, 3, 5, 3, 7]))


if __name__ == "__main__":
	test()
