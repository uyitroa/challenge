#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
	int generate(vector<string> &words, vector<string> &combination, string currentString = "",int x = 0, int currentIndex = 0) {
		if(x >= words.size()) {
			combination[currentIndex] = currentString;
			currentIndex++;
			return currentIndex;
		}
		for(int y = 0; y < words.size(); y++) {
			currentIndex = generate(words, combination, currentString + words[y], x + 1, currentIndex);
		}
		return currentIndex;
	}

	int in(string s, const vector<string> &combo) {
		for(int x = 0; x < combo.size(); x++) {
			if(s == combo[x])
				return 1;
		}
		return 0;
	}

	vector<int> findSubstring(string s, vector<string>& words) {
		vector<string> combination (pow(words.size(), words.size()));
		vector<int> result;
		generate(words, combination);
		int size = combination[words.size() - 1].length();
		for(int x = 0; x < s.length() - size + 1; x++) {
			cout << "substrin: " << s.substr(x, size) << "\n";
			if(in(s.substr(x, size), combination)) {
				result.push_back(x);
				x += size - 1;
			}
		}
		return result;
	}
};
int main() {
	Solution solution;
	vector<string> s = {"words", "students"};
	string sh = "mywordsstudentsisstudentswords";
	vector<int> shit = solution.findSubstring(sh, s);
	cout << shit[1] << "\n";
	return 0;
}
