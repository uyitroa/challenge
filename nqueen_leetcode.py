class Solution:
	def go(self, n, cur_result, cur_index, cur_row):
		"""
		:param cur_index: list of index of current branch
		:param cur_result: list of string of current branch
		:param n: int
		:param cur_row: int
		:return: void
		"""
		if cur_row == n:
			self.result += 1
			return
		for col in range(n):
			if self.collapse(col, cur_index, cur_row):
				continue
			string = '.' * col + 'Q' + '.' * (n - col - 1)
			cur_result[cur_row] = string
			cur_index[cur_row] = col
			self.go(n, cur_result, cur_index, cur_row + 1)
			cur_index[cur_row] = -1
			cur_result[cur_row] = ''

	def solveNQueens(self, n):
		self.result = 0
		cur_result = [''] * n
		cur_index = [-1] * n
		self.go(n, cur_result, cur_index, 0)

		return self.result

	def collapse(self, col, cur_index, cur_row):
		for i in range(cur_row):
			index = cur_index[i]
			if index == -1:
				return False
			if index - cur_row + i == col or index + cur_row - i == col or index == col:
				return True
		return False


def test():
	solution = Solution()
	print(solution.solveNQueens(9))


test()
