class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        // board status indicator (partial solution)
        unordered_set<int> rows;
        unordered_set<int> cols;
        unordered_set<int> posDiag;
        unordered_set<int> negDiag;
        vector<string> partialBoard(n, string(n, '.'));
        // container for results
        vector<vector<string>> results;

        backtrackNQueens(n, 0, rows, cols, posDiag, negDiag, partialBoard, results);

        return results;
    }

    void backtrackNQueens(int n, int row, unordered_set<int>& rows, unordered_set<int>& cols, unordered_set<int>& posDiag, unordered_set<int>& negDiag, vector<string>& partialBoard, vector<vector<string>>& results) {
        // termination condition: has surpassed the last row
        if(row >= n) {
            results.push_back(partialBoard);
            return;
        }

        // incrementally build partial solution
        // may put queen on any col of the current row as long as constrains hold
        // check for constrains
        for(int col = 0; col < n; col++) {
            if( rows.find(row) != rows.end()
              || cols.find(col) != cols.end()
              || posDiag.find(row - col) != posDiag.end()
              || negDiag.find(row + col) != negDiag.end()) {
                // constrain violated, no queen placed on this col
                partialBoard[row][col] = '.';
                continue;
            }

            // queen can be placed on this col
            // update partial solution
            partialBoard[row][col] = 'Q';

            // update status indicator
            rows.insert(row);
            cols.insert(col);
            posDiag.insert(row - col);
            negDiag.insert(row + col);

            backtrackNQueens(n, row + 1, rows, cols, posDiag, negDiag, partialBoard, results);

            // restore status indictor
            rows.erase(row);
            cols.erase(col);
            posDiag.erase(row - col);
            negDiag.erase(row + col);
            // restore partial solution
            partialBoard[row][col] = '.';
        }
    }
};
