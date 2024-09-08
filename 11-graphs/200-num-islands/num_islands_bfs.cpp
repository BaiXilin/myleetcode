class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // use BFS as the graph traversal technique
        // iterate thr grid, perform bfs on every 1
        // the bfs should turn every connected 1 to 0
        int numIslands = 0;
        // bfs require a queue
        queue<pair<int, int>> bfsQueue;

        if(grid.empty())
            return 0;       // rule out edge case

        int row = grid.size();
        int col = grid[0].size();

        for(int r = 0; r < row; r++)
            for(int c = 0; c < col; c++)
                if(grid[r][c] == '1') {
                    numIslands++;
                    bfs(grid, bfsQueue, r, c, row, col);
                }

        return numIslands;
    }

    // iterative bfs
    void bfs(vector<vector<char>>& grid, queue<pair<int, int>>& bfsQueue, 
      int r, int c, int row, int col) {
        // rule out invalid coordinate or not an island
        if(r < 0 || c < 0 || r >= row || c >= col || grid[r][c] == '0')
            return;

        // add current island to the queue
        bfsQueue.push({r, c});

        while(!bfsQueue.empty()) {
            r = bfsQueue.front().first;
            c = bfsQueue.front().second;
            bfsQueue.pop();

            // adds all neighboring islands to the queue
            if(isAnIsland(grid, r + 1, c, row, col)) {
                grid[r + 1][c] = '0';       // island has been visited
                bfsQueue.push({r + 1, c});  // traverse it later
            }
            if(isAnIsland(grid, r - 1, c, row, col)) {
                grid[r - 1][c] = '0';
                bfsQueue.push({r - 1, c});
            }
            if(isAnIsland(grid, r, c + 1, row, col)) {
                grid[r][c + 1] = '0';
                bfsQueue.push({r, c + 1});
            }
            if(isAnIsland(grid, r, c - 1, row, col)) {
                grid[r][c - 1] = '0';
                bfsQueue.push({r, c - 1});
            }
        }
    }

    bool isAnIsland(vector<vector<char>>& grid, int r, int c, int row, int col) {
            // valid coordinate?
            if(r < 0 || c < 0 || r >= row || c >= col)
                return false;
            // is an island?
            if(grid[r][c] != '1')
                return false;
            return true;
    }
};
