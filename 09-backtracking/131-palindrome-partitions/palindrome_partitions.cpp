#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        // container for results
        vector<vector<string>> results;
        // container for partial solution
        vector<string> partialRes;
        int splitIndex;

        for(splitIndex = 1; splitIndex <= s.length(); splitIndex++) {
            backtrackPartition(s, splitIndex, partialRes, results);
        }

        return results;
    }

    void backtrackPartition(string s, int splitIndex, vector<string>& partialRes, vector<vector<string>>& results) {
        // check if the substr left of the split is a palindrome
        if(!isPalindrome(s, 0, splitIndex))
            return; // invalid partition
        // left substr is a palindrome
        partialRes.push_back(s.substr(0, splitIndex));

        s = s.substr(splitIndex);

        // check if the right substr is a palindrome
        if(s.length() == 0)
            results.push_back(partialRes);

        for(splitIndex = 1; splitIndex <= s.length(); splitIndex++) {
            backtrackPartition(s, splitIndex, partialRes, results);
        }
        partialRes.pop_back();
    }

    bool isPalindrome(string s, int startIndex, int endIndex) {
        if(startIndex == endIndex - 1)
            return true;
        while(startIndex < endIndex - 1) {
            if(s[startIndex] != s[endIndex - 1])
                return false;
            startIndex++;
            endIndex--;
        }

        return true;
    }
};

int main() {
    string s = "aab";
    Solution sol;

    auto ret = sol.partition(s);

    for(int i = 0; i < ret.size(); i++) {
        for(int j = 0; j < ret[i].size(); j++)
            cout << ret[i][j] << " ";
        cout << endl;
    }
}
