#include <vector>
#include <queue>
#include <utility>
#include <map>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
		// rule out the empty grid case
		if(grid.empty())
			return 0;

		int row = grid.size();
		int col = grid[0].size();

		// possible that there multiple rotting oranges at the start
		queue<pair<int, int>> toVisit;
		map<pair<int, int>, bool> visited;
		// record propagation time
		int time = -1;

		// initial scan of the grid: look for original rotting oranges
		// also check if there are oranges in the grid
		bool hasOrange = false;
		for(int r = 0; r < row; r++)
			for(int c = 0; c < col; c++) {
				if(grid[r][c] == 2)
					toVisit.push({r, c});
				if(grid[r][c] == 1 || grid[r][c] == 2)
					hasOrange = true;
			}
		
		// I don't like this
		// but it is caused by weird return values required by the question
		// if no orange is in the grid, then the time taken to rot "all" is 0
		// if only fresh orange in the grid, then returns -1 (final scan)
		if(!hasOrange)
			return 0;
				

		// rot begins propagating...
		while(!toVisit.empty()) {
			time += 1;
			
			int numRottingOranges = toVisit.size();
			for(int i = 0; i < numRottingOranges; i++) {
				// rotting oranges propage one layer out
				int r = toVisit.front().first;
				int c = toVisit.front().second;
				toVisit.pop();

				bfs(grid, toVisit, r + 1, c, row, col);
				bfs(grid, toVisit, r - 1, c, row, col);
				bfs(grid, toVisit, r, c + 1, row, col);
				bfs(grid, toVisit, r, c - 1, row, col);
			}
		}

		// final scan of the grid: look for oranges not rotted
		for(int r = 0; r < row; r++)
			for(int c = 0; c < col; c++)
				if(grid[r][c] == 1)
					return -1;

		return time;
    }

	void bfs(vector<vector<int>>& grid, queue<pair<int, int>>& toVisit, 
			int r, int c, int row, int col) {
		// check for invalid coordinate or graph boundary
		if(r < 0 || c < 0 || r >= row || c >= col)
			return;
		if(grid[r][c] != 1)
			return;		// can only propagate to fresh oranges
		
		// this orange is rotting
		grid[r][c] = 2;
		toVisit.push({r, c});
	}
};
