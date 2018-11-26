class Solution:
	def divisible(self, coins, num):
		for index in range(len(coins) - 1, -1, -1):
			coin = coins[index]
			if num % coin == 0:
				return coin
		return -1

	def convert_to_dict(self, coins):
		my_dict = {}
		for x in coins:
			my_dict[x] = 0
		return my_dict

	def add(self, list_sum_coins, coins, my_dict):
		reset_index = 0
		n = 0
		for x in range(len(list_sum_coins)):
			list_sum_coins[x] += 1
			if list_sum_coins[x] == coins[x]:
				my_dict[coins[x]] += 1
				reset_index = x
			n += my_dict[coins[x]]

		count = 0
		for coin in my_dict:
			list_sum_coins[count] = 0
			if count == reset_index:
				break
			n -= my_dict[coin]
			my_dict[coin] = 0
			count += 1
		return n

	def distribute(self, coins, sum):
		print(coins, sum)
		cur_coin = self.convert_to_dict(coins)
		min_before_biggest = 0
		if sum > coins[-1] * coins[-2]:
			min_before_biggest = int((sum - (coins[-1] * coins[-2])) / coins[-1])
			sum = sum - (min_before_biggest * coins[-1])

		list_sum_coin = [0] * len(coins[1:])
		min_coin = {}
		n_min_coin = -1
		n_coin = 0
		divisible_step = self.get_divisible_step(coins)
		for x in range(sum):
			if x != 0:
				n_coin = self.add(list_sum_coin, coins, cur_coin)
				if n_coin > n_min_coin:
					continue

			coin = self.divisible(coins, sum - x)
			if coin != -1:
				n = (sum - x) / coin
				maybe_min_coin = n_coin + n
				if maybe_min_coin < n_min_coin or n_min_coin == -1:
					n_min_coin = maybe_min_coin
					min_coin = dict(cur_coin)
					min_coin[coin] += n
					print(x)
		min_coin[coins[-1]] += min_before_biggest
		n_min_coin += min_before_biggest
		return n_min_coin#, min_coin

	# [2, 2, 1, 2, 2, 2, 2, 2]
	def get_divisible_step(self, coins):



def test():
	solution = Solution()
	print(solution.distribute([1, 2, 5, 10, 20, 50, 100, 200, 500], 123456789))

if __name__ == "__main__":
	test()