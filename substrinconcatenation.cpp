#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int countsize(vector<string> &words) {
		int size = 0;
		for(int x = 0; x < words.size(); x++) {
			size += words[x].length();
		}
		return size;
	}

	int check(string s, vector<string> words) {
		int firstsize = 0;
		int vectorsize = words.size();

		for(int x = 0; x < vectorsize; x++) {
			if(s.substr(0, words[x].length()) == words[x]) {
				if(firstsize == 0)
					firstsize = words[x].length();
				s = s.substr(words[x].length(), s.length() - words[x].length()); 
				words[x] = words[vectorsize - 1];
				vectorsize--;
				x = -1;
			}
		}
		if(s == "")
			return firstsize;
		return 0;
	}

	vector<int> findSubstring(string s, vector<string> &words) {
		if(s.length() == 0 || words.size() == 0)
			return {};

		vector<int> pos;
		int size = countsize(words);
		for(int x = 0; x < s.length() - size + 1; x++) {
			int in = check(s.substr(x, size), words);
			if(in) {
				pos.push_back(x);
				x += in - 1;
			}
		}
		return pos;
	}
};

void printVector(vector<int> s) {
	for(int x = 0; x < s.size(); x++) {
		cout << s[x] << " ";
	}
	cout << "\n";
}

int main() {
	Solution solution;
	vector<string> words = {"bar", "foo"};
	string  s = "barfoothefoobarman";
	vector<int> asdf = solution.findSubstring(s, words);
	printVector(asdf);
	return 0;
}
