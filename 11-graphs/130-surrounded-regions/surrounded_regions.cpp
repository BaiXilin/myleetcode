#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
		// rule out empty board case
		if(board.empty())
			return;

		int row = board.size();
		int col = board[0].size();

		// create a new board, init to all 'X'
		vector<vector<char>> dupBoard(row, vector<char>(col, 'X'));

		// perform BFS on very edge cell in board
		// turn X to O on new board if reachable from edges
		queue<pair<int, int>> toVisit;
		for(int r = 0; r < row; r++) {
			for(int c = 0; c < col; c++) {
				if((r == 0 || r == row - 1 || c == 0 || c == col - 1)
						&& board[r][c] == 'O')
					toVisit.push({r, c});
			}
		}

		vector<vector<int>> dirGradient = {
			{1, 0},
			{-1, 0},
			{0, 1},
			{0, -1}};

		while(!toVisit.empty()) {
			int x = toVisit.front().first;
			int y = toVisit.front().second;
			toVisit.pop();

			// check for coordinate validity
			if(x < 0 || y < 0 || x >= row || y >= col)
				continue;
			// check if not on region boundary
			if(board[x][y] == 'X')
				continue;
			
			// update new board to O
			dupBoard[x][y] = 'O';
			// update old board to X to indicate visited
			board[x][y] = 'X';

			// traverse 4 directions
			for(int i = 0; i < 4; i++)
				toVisit.push({x + dirGradient[i][0], y + dirGradient[i][1]});
		}
		
		// transplant result into original board
		for(int r = 0; r < row; r++)
			for(int c = 0; c < col; c++)
				board[r][c] = dupBoard[r][c];
    }
};
