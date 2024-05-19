class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // construct a mapping between digits and the letters
        unordered_map<char, vector<char>> letterMap;
        char letter = 'a';

        for(char digit = '2'; digit <= '9'; digit++) {
            for(int j = 0; j < 3; j++) {
                letterMap[digit].push_back(letter);
                letter++;
            }
        }

        // container for results
        vector<string> results;
        // container for partial solution
        string combo;

        if(!digits.empty())
            backtrackLetterCombinations(digits, 0, letterMap, results, combo);

        return results;
    }

    void backtrackLetterCombinations(string& digits, int index, unordered_map<char, vector<char>>& letterMap, vector<string>& results, string& combo) {
        // termination condition: has examined the entire digits string
        if(index >= digits.length()) {
            // current partial solution is now complete
            results.push_back(combo);
            return;
        }

        // incrementally build up partial solution
        for(auto& letter : letterMap[digits[index]]) {
            combo += letter;
            backtrackLetterCombinations(digits, index + 1, letterMap, results, combo);
            // restore combo
            combo.pop_back();
        }
    }
};
