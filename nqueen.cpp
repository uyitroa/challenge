#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void printVector(vector<string> &s) {
	for(int x = 0; x < s.size(); x++)
		cout << s[x] << "\n";
	cout << "\n\n\n";
}

class Solution {
private:
	void printBoard(vector<vector<int> > &board) {
		for(int i = 0; i < board.size(); i++) {
			for(int j = 0; j < board[0].size(); j++) {
				cout << board[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
public:
/* 	bool is_attacked(int i, int j, vector<vector<int> > &board) {
		return board[i][j] == 1;
	} */

	vector<vector<int> > newboard(int i, int j, vector<vector<int> > board) {
		for(int x = 0; x < board.size(); x++) {
				board[i][x] = 1; //row
				board[x][j] = 1; //column
			//diagonal
			if(x != j) {
				int diff = sqrt((x - j) * (x - j));
				if(i - diff >= 0)
					board[i - diff][x] = 1;
				if(i + diff < board.size()) {
					board[i + diff][x] = 1;
				}
			}
		}

		return board;
	}

	vector<string> check(int n, vector<vector<int> > board, vector<string> result) {
		//printBoard(board);
		//printVector(result);
		if(n == 0)
			return result;
		for(int i = 0; i < board.size(); i++) {
			for(int j = 0; j < board.size(); j++) {
				if(board[i][j] == 0) {
					const int SIZE = board[0].size();
					vector<string> temp = result;
					temp[SIZE - n] = to_string(i) + " " + to_string(j);
					temp = check(n - 1, newboard(i, j, board), temp);
					if(!temp.empty())
						return temp;

				}
			}
		}
		return vector<string>();
	}

	vector<string> findNqueen(int n) {
		vector<vector<int> > board(n, vector<int> (n, 0));
		vector<string> result(n);
		result = check(n, board, result);
		return result;
	}
};

int main() {
	Solution solution;
	vector<string> s = solution.findNqueen(9);
	printVector(s);
	return 0;
}