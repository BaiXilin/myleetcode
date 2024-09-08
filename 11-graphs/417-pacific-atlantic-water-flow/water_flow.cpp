#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
		vector<vector<int>> cellsToBothSea;

		// rule out empty input grid case
		if(heights.empty())
			return cellsToBothSea;

		int row = heights.size();
		int col = heights[0].size();
		
		// init a grid of pairs of booleans
		// indicate if a cell can reach two seas
		vector<vector<pair<bool, bool>>> toSea(row,
		  vector<pair<bool, bool>>(col, {false, false})); // same dimension
		
		// take every cell on the edge as a source
		// need to take note of which sea that cell is neighboring
		struct qCell {
			int r;
			int c;
			bool fromPacific = false;
			bool fromAtlantic = false;
		};
		queue<qCell> toVisit;

		for(int r = 0; r < row; r++) {
			for(int c = 0; c < col; c++) {
				bool topEdge = false, bottomEdge = false, leftEdge = false, rightEdge = false;
				if(r == 0)
					topEdge = true;
				if(r == row - 1)
					bottomEdge = true;

				if(c == 0)
					leftEdge = true;
				if(c == col - 1)
					rightEdge = true;
				
				toVisit.push({r, c, topEdge || leftEdge, bottomEdge || rightEdge});
			}
		}

		vector<vector<int>> dirGradients = 
				{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

		// start bfs traversal
		while(!toVisit.empty()) {
			// retrieve the cell to be examined
			int x = toVisit.front().r;
			int y = toVisit.front().c;
			bool fromPacific = toVisit.front().fromPacific;
			bool fromAtlantic = toVisit.front().fromAtlantic;
			toVisit.pop();

			// check if coordinate is out of grid
			if(x < 0 || y < 0 || x >= row || y >= col)
				continue;
			// check if this cell has already been flowed
			// (no new flow info on this flow branch)
			if(toSea[x][y].first && toSea[x][y].second)
				continue;
			if(toSea[x][y].first == fromPacific
					&& toSea[x][y].second == fromAtlantic)
				continue;

			// update this cell's flow
			toSea[x][y].first |= fromPacific;
			toSea[x][y].second |= fromAtlantic;

			// pass the flow info to all four directions
			for(int i = 0; i < 4; i++) {
				int next_x = x + dirGradients[i][0];
				int next_y = y + dirGradients[i][1];

				if(next_x < 0 || next_y < 0 || next_x >= row || next_y >= col)
					continue;
				// water can only flow from larger or equal height cells
				if(heights[next_x][next_y] >= heights[x][y])
					toVisit.push({next_x, next_y, fromPacific, fromAtlantic});
			}
		}

		// final scan: record the cells that are reachable from both seas
		for(int r = 0; r < row; r++)
			for(int c = 0; c < col; c++)
				if(toSea[r][c].first && toSea[r][c].second)
					cellsToBothSea.push_back({r, c});

		return cellsToBothSea;
    }
};

int main() {
	Solution sol;
	vector<vector<int>> heights = {
		{1,2,2,3,5}, 
		{3,2,3,4,4}, 
		{2,4,5,3,1}, 
		{6,7,1,4,5},
		{5,1,1,2,4}};

	vector<vector<int>> result = sol.pacificAtlantic(heights);
}
