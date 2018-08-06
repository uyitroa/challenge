#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm> // for std::copy

using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int> &nums) {
		//bubble sort
		int vectorsize = nums.size();
		int min = 1;
		for(int x = 0; x < vectorsize; x++) {
			int same = 0;
			for(int y = vectorsize - 1; y >= 0; y--) {
				if(min == nums[y]) {
					min++;
					same = 1;
				}
			}
			if(!same)
				return min;
		}
		return min;

	}
};

int main() {
	Solution solution;

	cout << solution.firstMissingPositive(asdf) << "\n";

}
