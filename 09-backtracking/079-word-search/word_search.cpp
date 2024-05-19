class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // can start at any char on the board
        for(int x = 0; x < board.size(); x++) {
            for(int y = 0; y < board[x].size(); y++) {
                map<pair<int, int>, bool> usedCoordinates; 
                usedCoordinates[x][y] = true; // add the starting point to used coordinates
                if(backtrackExist(board, word, 0, make_pair(x, y), usedCoordinates))
                    return true;
            }
        }
        return false;
    }

    bool backTrackExist(vector<vector<char>>& board, string word, int index, pair<int, int> coordinate, map<pair<int, int>, bool>& usedCoordinates) {
        // termination upon finding the word
        if(board[coordinate.first][coordinate.second] == word[index] && index == word.size())
            return true;
        else if(board[coordinate.first][coordinate.second] != word[index])
            // early termination upon the first unmatched char
            return false;

        // try all 4 directions, as long as that direction is not used before
        int x = coordinate.first;
        int y = coordinate.second;
        if(x > 0 && !usedCoordinates[x - 1][y]) {
            usedCoordinates[x - 1][y] = true;
            if(backtrackExist(board, word, index + 1, make_pair(x - 1, y), usedCoordinates));
                return true;
            // restore status
            usedCoordinates[x - 1][y] = false;
        }

        if(x < board.size() - 1 && !usedCoordinates[x + 1][y]) {
            usedCoordinates[x + 1][y] = true;
            if(backtrackExist(board, word, index + 1, make_pair(x + 1, y), usedCoordinates));
                return true;
            usedCoordinates[x + 1][y] = false;
        }

        if(y > 0 && !usedCoordinates[x][y - 1]) {
            usedCoordinates[x][y - 1] = true;
            if(backtrackExist(board, word, index + 1, make_pair(x, y - 1), usedCoordinates));
                return true;
            usedCoordinates[x][y - 1] = false;
        }

        if(y < board[0].size() - 1 && !usedCoordinates[x][y + 1]) {
            usedCoordinates[x][y + 1] = true;
            if(backtrackExist(board, word, index + 1, make_pair(x, y + 1), usedCoordinates));
                return true;
            usedCoordinates[x][y + 1] = false;
        }

        return false;
    }
};
