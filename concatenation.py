class Solution:
	def findSubstring(self, s, words):
		if not s or not words or len(s) < len(words[0]):
			return []

		word_dict, word_index = self.convert_dict(words)
		if not word_dict:
			return []

		word_size = len(words[0])
		full_size = len(words) * word_size
		indexes = self.get_indexes(s, word_index, word_size)
		start_index = [-1] * word_size
		tmp_word_dict = [0] * word_size
		for x in range(word_size):
			tmp_word_dict[x] = dict(word_dict)
		consecutive = [0] * word_size
		cur_turn = 0
		result = []
		for index, word_id in enumerate(indexes):
			if word_id != -1:
				word = words[word_id]
				if start_index[cur_turn] == -1:
					start_index[cur_turn] = index
					tmp_word_dict[cur_turn][word] -= 1
					consecutive[cur_turn] += 1
				else:
					if tmp_word_dict[cur_turn][word] != 0:
						tmp_word_dict[cur_turn][word] -= 1
						consecutive[cur_turn] += 1
					else:
						for x in range(start_index[cur_turn], index + 1, word_size):
							if tmp_word_dict[cur_turn][word] != 0:
								start_index[cur_turn] = x
								consecutive[cur_turn] += 1
								tmp_word_dict[cur_turn][word] -= 1
								break
							cur_word = words[indexes[x]]
							tmp_word_dict[cur_turn][cur_word] += 1
							consecutive[cur_turn] -= 1

				if consecutive[cur_turn] == len(words):
					result.append(start_index[cur_turn])

					word_begin = words[indexes[start_index[cur_turn]]]
					tmp_word_dict[cur_turn][word_begin] += 1
					start_index[cur_turn] += word_size
					consecutive[cur_turn] -= 1
			else:
				start_index[cur_turn] = -1
				tmp_word_dict[cur_turn] = dict(word_dict)
				consecutive[cur_turn] = 0

			cur_turn = cur_turn + 1 if cur_turn < word_size - 1 else 0

		return result

	def convert_dict(self, word_list):
		normal_len = len(word_list[0])
		my_dict = {}
		my_dict2 = {}
		for index, word in enumerate(word_list):
			if len(word) != normal_len:
				return {}, {}
			if word in my_dict:
				my_dict[word] += 1
			else:
				my_dict[word] = 1
				my_dict2[word] = index
		return my_dict, my_dict2

	def get_indexes(self, s, words, word_size):
		indexes = [-1] * (len(s))
		for s_index in range(len(s)):
			sub = s[s_index:s_index + word_size]
			if sub in words:
				indexes[s_index] = words[sub]
		return indexes


def test():
	solution = Solution()
	print(solution.findSubstring("wordgoodgoodgoodbestword", ["word", "good", "best", "word"]))


if __name__ == "__main__":
	test()


