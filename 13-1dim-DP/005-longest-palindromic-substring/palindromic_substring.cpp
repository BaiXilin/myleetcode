#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // idea: for two positions i and j, if s[i] == s[j] and s[i+1, j-1] is a palindrome, then s[i, j] is a palindrome
        //       for even palindrome, if s[i] == s[i+1], expand to palindrome of len 4, 6...

        // dp[i][j] = true if s[i, j] is a palindrome
        bool dp[s.size()][s.size()] = {false};
        pair<int, int> ans_positions = make_pair(0, 0);

        // adjacent chars if they are palindrome of length 2
        for(int i = 0; i < s.size() - 1; i++)
            if(s[i] == s[i + 1])
                dp[i][i + 1] = true;

        // expand on the length of palindrome starting from length of 3
        for(int diff = 2; diff < s.size(); diff++) {
            for(int i = 0; i < s.size() - diff; i++) {
                int j = i + diff;
                if(s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    ans_positions = make_pair(i, j - i + 1);
                }
            }
        }

        return s.substr(ans_positions.first, ans_positions.second);
    }
};
