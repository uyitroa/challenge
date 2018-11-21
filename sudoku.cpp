#include <iostream>
#include <vector>
using namespace std;

int BOARD_SIZE = 9;

void printVector(vector<vector<char>> &ok)
{
	for (int y = 0; y < BOARD_SIZE; y++)
	{
		for (int x = 0; x < BOARD_SIZE; x++)
		{
			cout << ok[y][x] << " ";
		}
		cout << "\n";
	}
}

class Solution {
private:
	void findPoss(vector<vector<char> > &board, int x, int y, vector<char> &pos) {
		char p[9] = {0};
		int row_square = 0;
		int square_x = (x / 3) * 3; // (int) 2 / 3 * 3 = 0
		int square_y = (y / 3) * 3;
		for(int z = 0; z < BOARD_SIZE; z++) {

			if(board[z][x] != '.') {
				if (p[board[z][x] - 49] == 0) {
					char number = board[z][x];
					p[number - 49] = number;
				}
			}
			if(board[y][z] != '.') {
				if (p[board[y][z] - 49] == 0) {
					char number = board[y][z];
					p[number - 49] = number;
				}
			}
			//square
			if (board[square_y][square_x] != '.') {
				if (p[board[square_y][square_x] - 49] == 0) {
					char number = board[square_y][square_x];
					p[number - 49] = number;
				}
			}
			square_x++;
			if (square_x % 3 == 0) {
				square_x = (x / 3) * 3;
				square_y++;
			}
		}

		for(int c = 0; c < BOARD_SIZE; c++) {
			if(p[c] == 0)
				pos.push_back(c + 49);
		}
	}
	bool next(vector<vector<char> > &board, int *a, int *b) {
		while(board[*b][*a] != '.') {
			*a += 1;
			if(*a == BOARD_SIZE) {
				*a = 0;
				*b += 1;

				//if finished
				if(*b == BOARD_SIZE)
					return true;
			}
		}
		return false;
	}

	bool solution(vector<vector<char> > &board, int x, int y) {
		vector<char> pos;
		findPoss(board, x, y, pos);
		int tmp_x = x;
		int tmp_y = y;
		for(char c : pos) {
			board[y][x] = c;
			if(next(board, &tmp_x, &tmp_y))
				return true;
			bool finished = solution(board, tmp_x, tmp_y);

			if(finished)
				return true;
		}
		board[y][x] = '.';
		return false;
	}
public:
  	void solveSudoku(vector<vector<char> > &board) {
		  int x = 0;
		  int y = 0;
		  next(board, &x, &y);
		  solution(board, x, y);
	}
};

int main() {
	Solution solution;
	vector<vector<char> > board =
	{{'.','5','.','9','.','.','.','.','.'},
	{'.','.','9','.','.','.','.','3','.'},
	{'.','.','.','.','1','.','.','4','.'},
	{'6','.','.','.','.','.','.','.','.'},
	{'8','.','.','4','.','.','.','6','.'},
	{'7','.','.','5','.','.','9','2','8'},
	{'9','.','6','.','3','2','1','.','.'},
	{'.','2','.','.','.','5','.','.','.'},
	{'.','.','.','.','.','.','.','.','4'}};
	solution.solveSudoku(board);
	printVector(board);
	return 0;
}
