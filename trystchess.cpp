#include <iostream>
#include <vector>
using namespace std;
const int BOARD_SIZE = 10;
class Solution {
private:
	vector<vector<int> > board;
public:
	int generatePossibility(int x, int y, vector<int> &coordx, vector<int> &coordy, bool end = false) {
		int size = 0;
		if(y - 2 >= 0) { // up
			if(x - 1 >= 0) {
				if(end == true) {
					if(board[y - 2][x - 1] != 1) {
						size++;
						board[y - 2][x - 1] = 1;
					}
				} else {
					coordx.push_back(x - 1);
					coordy.push_back(y - 2);
					size++;
				}
			}
			if(x + 1 < BOARD_SIZE) {
				if(end == true) {
					if(board[y - 2][x + 1] != 1) {
						size++;
						board[y - 2][x + 1] = 1;
					}
				} else {
					coordx.push_back(x + 1);
					coordy.push_back(y - 2);
					size++;
				}
			}
		}

		if(y + 2 < BOARD_SIZE) { //down
			if(x - 1 >= 0) {
				if(end == true) {
					if(board[y + 2][x - 1] != 1) {
						size++;
						board[y + 2][x - 1] = 1;
					}
				} else {
					coordx.push_back(x - 1);
					coordy.push_back(y + 2);
					size++;
				}
			}
			if(x + 1 < BOARD_SIZE) {
				if(end == true) {
					if(board[y + 2][x + 1] != 1) {
						size++;
						board[y + 2][x + 1] = 1;
					}
				} else {
					coordx.push_back(x + 1);
					coordy.push_back(y + 2);
					size++;
				}
			}
		}

		if(x - 2 >= 0) { //left
			if(y - 1 >= 0) {
				if(end == true) {
					if(board[y - 1][x - 2] != 1) {
						size++;
						board[y - 1][x - 2] = 1;
					}
				} else {
					coordx.push_back(x - 2);
					coordy.push_back(y - 1);
					size++;
				}
			}
			if(y + 1 < BOARD_SIZE) {
				if(end == true) {
					if(board[y + 1][x - 2] != 1) {
						size++;
						board[y + 1][x - 2] = 1;
					}
				} else {
					coordx.push_back(x - 2);
					coordy.push_back(y + 1);
					size++;
				}
			}
		}

		if(x + 2 < BOARD_SIZE) { //right
			if(y - 1 >= 0) {
				if(end == true) {
					if(board[y - 1][x + 2] != 1) {
						size++;
						board[y - 1][x + 2] = 1;
					}
				} else {
					coordx.push_back(x + 2);
					coordy.push_back(y - 1);
					size++;
				}
			}
			if(y + 1 < BOARD_SIZE) {
				if(end == true) {
					if(board[y + 1][x + 2] != 1) {
						size++;
						board[y + 1][x + 2] = 1;
					}
				} else {
					coordx.push_back(x + 2);
					coordy.push_back(y + 1);
					size++;
				}
			}
		}
		return size;
	}

	int calcBlock(int x, int y, int nblock, int size = 0) {
		int actualsize = 0;
		vector<int> coordx;
		vector<int> coordy;
		cout << "x: " << x << "y: " << y << "\n";
		if(nblock == 1) {
			size += generatePossibility(x, y, coordx, coordy, true);
			return size;
		}
		actualsize = generatePossibility(x, y, coordx, coordy);
		for(int x = 0; x < actualsize; x++) {
			size += calcBlock(coordx[x], coordy[x], nblock - 1, size);
		}
		return size;
	}

	int solve(int x, int y, int nblock, vector<vector<int> > board) {
		this->board = board;
		return calcBlock(x, y, nblock);
	}
};

int main() {
	Solution solution;
	vector<vector<int> > board(BOARD_SIZE, vector<int> (BOARD_SIZE, 0));
	cout << solution.solve(0, 0, 2, board) << "\n";
	return 0;
}