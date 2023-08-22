#include <iostream>
#include <array>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int board_length = 9;
        array<unordered_set<char>, board_length> rows;
        array<unordered_set<char>, board_length> cols;
        array<array<unordered_set<char>, board_length>, board_length> blocks;
        // fill the maps
        for(int i = 0; i < board_length; i++) {
            for(int j = 0; j < board_length; j++) {
                char c = board[i][j];
                // ignore dot
                if(!isDigit(c))
                    continue;

                // insert to rows
                if(rows[i].find(c) == rows[i].end())
                    rows[i].insert(c);
                else
                    return false;

                // insert to cols
                if(cols[j].find(c) == cols[j].end())
                    cols[j].insert(c);
                else
                    return false;

                // insert to blocks
                if(blocks[i/3][j/3].find(c) == blocks[i/3][j/3].end())
                    blocks[i/3][j/3].insert(c);
                else
                    return false;
            }
        }
        return true;
    }

    bool isDigit(char c) {
        if(c - '0' >= 1 && c - '0' <= 9)
            return true;
        return false;
    }
};

int main() {
    //vector<vector<char>> board = {{'8', '3', '.'}, {'1', '2', '3'}, {'7', '.', '.'}};
    vector<vector<char>> board1  = {{'8','3','.','.','7','.','.','.','.'},
                                  {'6','.','.','1','9','5','.','.','.'},
                                  {'.','9','8','.','.','.','.','6','.'},
                                  {'8','.','.','.','6','.','.','.','3'},
                                  {'4','.','.','8','.','3','.','.','1'},
                                  {'7','.','.','.','2','.','.','.','6'},
                                  {'.','6','.','.','.','.','2','8','.'},
                                  {'.','.','.','4','1','9','.','.','5'},
                                  {'.','.','.','.','8','.','.','7','9'}};

    vector<vector<char>> board2 = {{'5','3','.','.','7','.','.','.','.'},
                                   {'6','.','.','1','9','5','.','.','.'},
                                   {'.','9','8','.','.','.','.','6','.'},
                                   {'8','.','.','.','6','.','.','.','3'},
                                   {'4','.','.','8','.','3','.','.','1'},
                                   {'7','.','.','.','2','.','.','.','6'},
                                   {'.','6','.','.','.','.','2','8','.'},
                                   {'.','.','.','4','1','9','.','.','5'},
                                   {'.','.','.','.','8','.','.','7','9'}};
    

    Solution sol;
    std::cout << sol.isValidSudoku(board2) << std::endl;

    return 0;
}
