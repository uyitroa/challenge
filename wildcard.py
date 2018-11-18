class Solution:
	def add_question_mark(self, sub, index_question):
		if index_question:
			for x in index_question:
				if x < len(sub):
					sub = sub[:x] + '?' + sub[x + 1:]
		return sub

	def is_empty(self, s, p):
		empty_p = len(p) == 1
		empty_s = len(s) == 1
		if empty_p or empty_s:
			return empty_p and empty_s

	def check(self, s, p, index_question):
		"""
		:param s: fullstring
		:param p: array of string separated by '*'
		:param index_question: array of index of question mark
		:return: boolean
		"""
		current_index = 0
		current_pattern = p[current_index]
		from_asterisk = p[0] == ''
		index = 0
		while index < len(s):
			sub = self.add_question_mark(s[index:index + len(current_pattern)], index_question[current_index])

			if current_pattern == '':
				if current_index == len(p) - 1:
					return True
				from_asterisk = True
				current_index += 1
				current_pattern = p[current_index]
			elif current_index == len(p) - 1 and from_asterisk:
				if current_pattern == self.add_question_mark(s[len(s) - len(current_pattern):], index_question[current_index]):
					return True
				return False
			elif sub == current_pattern:
				from_asterisk = True
				current_index += 1
				s = s[index + len(current_pattern):]
				index = 0
				if current_index >= len(p):
					break
				current_pattern = p[current_index]

			elif not from_asterisk:
				return False
			else:
				index += 1
		if p[-1] == '':
			p = p[:-1]
		if len(s) != 0 or current_index < len(p):
			return False
		return True



	def isMatch(self, s, p):
		"""

		:param s: full string
		:param p: string with pattern
		:return: boolearn
		"""
		if s == p:
			return True
		if not p:
			return False
		splitted_string = ""
		array_pattern = []
		index_question = []
		current_index_question = []

		empty_begin = False
		empty_end = False
		if p[-1] == '*':
			p += '/'
			empty_end = True
		if p[0] == '*' and p[1] != "/":
			p = '/' + p
			empty_begin = True

		for index in range(len(p)):
			letter = p[index]
			if letter == '*':
				if splitted_string != '':
					array_pattern.append(splitted_string)
					index_question.append(current_index_question)
				current_index_question = []
				splitted_string = ''
			else:
				splitted_string += letter
			if letter == '?':
				current_index_question.append(len(splitted_string) - 1)

		array_pattern.append(splitted_string)
		index_question.append(current_index_question)
		if empty_begin:
			array_pattern[0] = ''
		if empty_end:
			array_pattern[-1] = ''

		if array_pattern == ['']:
			return True
		print(array_pattern)
		return self.check(s, array_pattern, index_question)


def test():
	solution = Solution()
	print(solution.isMatch("hi", "*?"))


if __name__ == "__main__":
	test()