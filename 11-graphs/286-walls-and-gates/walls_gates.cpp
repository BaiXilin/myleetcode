#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
		// rule out empty grid case
		if(grid.empty())
			return;

		int row = grid.size();
		int col = grid[0].size();

		queue<pair<int, int>> q;

		for(int r = 0; r < row; r++) {
			for(int c = 0; c < col; c++) {
				if(grid[r][c] == 0) {			// if treasure
					q.push({r, c});
				}
			}
		}

		vector<vector<int>> gradient = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

		while(!q.empty()) {
			int r = q.front().first;
			int c = q.front().second;
			q.pop();

			for(int i = 0; i < gradient.size(); i++) {
				int x = r + gradient[i][0];
				int y = c + gradient[i][1];

				// check for neighbor coordinate (x, y) validity
				if(x < 0 || y < 0 || x >= row || y >= col)
					continue;
				// check if that cell has been relaxed already
				if(grid[x][y] != INT_MAX)
					continue;

				q.push({x, y});
			}
		}
    }
};
