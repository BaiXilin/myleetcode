#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <utility>

using namespace std;

class Solution {
public:
    struct Node {
        char ch;
        bool isWordEnd = false;
        unordered_map<char, Node*> next;
    };

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // construct a trie to store all the words
        // given assumption: all words are unique
        Node root;
        Node *iter = &root;
        for(auto& word : words) {
            for(auto& c : word) {
                // determine if a trie node for the letter already exists
                if(iter->next.find(c) == iter->next.end())
                    iter->next[c] = new Node();
                iter->next[c]->ch = c;
                iter = iter->next[c];
            }
            iter->isWordEnd = true;
            iter = &root;
        }

        // container for all found words
        unordered_set<string> wordsFound;
        // partial solution needs to record the coordinates used
        map<pair<int, int>, bool> usedCoordinates;
        string partialWord = "";

        // traversing the trie from every location on board
        for(int row = 0; row < board.size(); row++) {
            for(int col = 0; col < board[row].size(); col++) {
                backtrackFindWords(board, iter, row, col, usedCoordinates, partialWord, wordsFound);
            }
        }

        // convert found words into return format, serve to eliminate duplicated words
        vector<string> retWordsFound;
        for(auto& w : wordsFound)
            retWordsFound.push_back(w);

        return retWordsFound;
    }

    void backtrackFindWords(vector<vector<char>>& board, Node* trieIter, int row, int col, 
                    map<pair<int, int>, bool>& usedCoordinates, string& partialWord, unordered_set<string>& wordsFound) {
        // termination condition: coordinate out of bound
        if(row < 0 || row >= board.size()
          || col < 0 || col >= board[row].size())
            return;

        // termination condition: coordinate has been used
        if(usedCoordinates[make_pair(row, col)])
            return;

        // termination condition: unmatched word
        char c = board[row][col];
        if(trieIter->next.find(c) == trieIter->next.end())
            return;
        
        // next char is matched. update trieIter
        trieIter = trieIter->next[c];

        partialWord += trieIter->ch;
        usedCoordinates[make_pair(row, col)] = true;

        // check if at word's end
        if(trieIter->isWordEnd)
            wordsFound.insert(partialWord);

        // traverse all 4 directions for words with the current partial word as prefix
        backtrackFindWords(board, trieIter, row + 1, col, usedCoordinates, partialWord, wordsFound);
        backtrackFindWords(board, trieIter, row - 1, col, usedCoordinates, partialWord, wordsFound);
        backtrackFindWords(board, trieIter, row, col + 1, usedCoordinates, partialWord, wordsFound);
        backtrackFindWords(board, trieIter, row, col - 1, usedCoordinates, partialWord, wordsFound);

        // restore partial solution
        partialWord.pop_back();
        usedCoordinates[make_pair(row, col)] = false;
    }
};

int main() {
    vector<vector<char>> board =   {{'o','a','a','n'},
                                    {'e','t','a','e'},
                                    {'i','h','k','r'},
                                    {'i','f','l','v'}};
    vector<string> words = {"oath","pea","eat","rain"};

    Solution sol;
    auto words_found = sol.findWords(board, words);

    for(auto word : words_found)
        std::cout << word << std::endl;
}
