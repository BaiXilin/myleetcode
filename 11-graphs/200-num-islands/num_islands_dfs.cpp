class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // idea: any graph traversal algorithm should work for this question
        // find the number of independent graphs == num of islands
        // choose to do a DFS

        if(grid.empty())
            return 0;

        int row = grid.size();
        int col = grid[0].size();

        int numIslands = 0;

        for(int r = 0; r < row; r++) {
            for(int c = 0; c < col; c++) {
                if(grid[r][c] == '1') {
                    dfs(grid, r, c, row, col);
                    numIslands++;
                }
            }
        }

        return numIslands;
    }

    void dfs(vector<vector<char>>& grid, int x, int y, int row, int col) {
        // check if coordinates out of grid bound
        if(x < 0 || y < 0 || x >= row || y >= col)
            return;

        // island tile visited. leave a mark
        grid[x][y] = '0';

        // recursively visit all neigorbing tiles
        dfs(grid, x + 1, y, row, col);
        dfs(grid, x - 1, y, row, col);
        dfs(grid, x, y + 1, row, col);
        dfs(grid, x, y - 1, row, col);
    }
};
