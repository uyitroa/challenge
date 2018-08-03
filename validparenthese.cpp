#include <iostream>
#include <vector>

class Solution {
	private:
		void printList(std::vector<int> &sex) {
			for(int x = 0; x < sex.size(); x ++) {
				std::cout << sex.at(x) << " ";
			}
		}
	public:
		void generateId(int len, std::vector<int> &sex) {
			sex.resize(len);
			for(int x = 0; x < len; x++) {
				sex.at(x) = x;
			}
		}

		int countlol(std::string code) {
			int max = 0;
			int currentCombo = 0;
			for(int x = 0; x < code.length(); x++) {
				if(code[x] != ' ') {
					currentCombo++;
				} else {
					if(currentCombo > max) {
						max = currentCombo;
					}
					currentCombo = 0;
				}
			}
			if (currentCombo > max)
				max = currentCombo;
			return max;
		}
		int longestValidParentheses(std::string s) {
			int currentIndex = 0;
			std::string cod(s.length(), ' ');
			std::vector<int> id {0};
			generateId(s.length(), id);

			while(currentIndex < s.length()) {

				if(s[currentIndex] == '(') {
					if(s[currentIndex + 1] == ')') {
						int real_index_openParenthese = id[currentIndex];
						int real_index_closeParenthese = id[currentIndex + 1];
						cod[real_index_openParenthese] = '&';
						cod[real_index_closeParenthese] = '&';
						s.erase(currentIndex, 2);
						id.erase(id.begin() + currentIndex);
						id.erase(id.begin() + currentIndex);
					} else {
						currentIndex++;
					}
				} else {
					if(s[currentIndex - 1] == '(') {
						int real_index_openParenthese = id[currentIndex - 1];
						int real_index_closeParenthese = id[currentIndex];
						cod[real_index_openParenthese] = '&';
						cod[real_index_closeParenthese] = '&';
						s.erase(currentIndex - 1, 2);
						id.erase(id.begin() + currentIndex - 1);
						id.erase(id.begin() + currentIndex - 1);
						currentIndex--;
					} else {
						currentIndex++;
					}
				}
			}
			int max = countlol(cod);
			return max;
		}
};

int main() {
	Solution solution;
	std::cout << solution.longestValidParentheses(")()())") << "\n";
}