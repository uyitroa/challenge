#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void printVector(vector<string> s, int size) {
	for(int x = 0; x < size; x++) {
		cout << s[x] << " ";
	}
	cout << "\n";
}

class Solution {
public:
	void generate(vector<string> words, vector<string> &combination, int vectorsize, string currentString = "") {
		if(vectorsize == 0) {
			combination.push_back(currentString);
		}
		for(int y = 0; y < vectorsize; y++) {
			string temp = words[y];
			words[y] = words[vectorsize - 1];

			generate(words, combination, vectorsize - 1, currentString + temp);
			words[y] = temp;
		}
	}

	int in(string s, const vector<string> &combo) {
		for(int x = 0; x < combo.size(); x++) {
			if(s == combo[x])
				return 1;
		}
		return 0;
	}

	vector<int> findSubstring(string s, vector<string>& words) {
		vector<string> combination;
		vector<int> result;
		if(words.size() == 0 || s.length() == 0)
			return {};
		generate(words, combination, words.size());
		int size = combination[0].length();
		for(int x = 0; x < s.length() - size + 1; x++) {
			if(in(s.substr(x, size), combination)) {
				result.push_back(x);
				//x += size - 1;
			}
		}
		return result;
	}
};
int main() {
	Solution solution;
	vector<string> s = {"asdf", "fds"};
	string sh = "";
	vector<int> shit = solution.findSubstring(sh, s);
	cout << shit[0] << "\n";
	return 0;
}
