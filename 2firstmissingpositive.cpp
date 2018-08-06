#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm> // for std::copy

using namespace std;
class Solution {
public:
	int firstMissingPositive(vector<int> &nums) {
		vector<int> newvector = nums;
		for(int x = 0; x < newvector.size(); x++) {
			int i = nums[x];
			if(i > 0 && i < nums.size() && nums[i - 1] != i)
				newvector[i - 1] = i;
		}

		for(int x = 0; x < newvector.size(); x++) {
			if(newvector[x] != x + 1)
				return x + 1;
		}
		return newvector.size() + 1;
	}
};

int main() {
	Solution solution;
	typedef std::istream_iterator<int> istream_iterator;
	std::ifstream file("numbers.txt");
	std::vector<int> input;

	file >> std::noskipws;
	std::copy(istream_iterator(file), istream_iterator(),
			  std::back_inserter(input));
	cout << solution.firstMissingPositive(input) << "\n";
	return 0;
}
