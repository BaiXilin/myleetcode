#include <string>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        // idea: Kinda the same question as Find the Longest Palindromic Substring
        //       Keep a 2d DP table that indicates if substr[i:j] is palindromic
        //       Use the table to fast determine if longer substr is palindromic
        //       Specifically, dp[i][j] = true if s[i]==s[j] and dp[i+1][j-1]==true

        // edge case: input string is empty, so no palindrome possible
        if(s.size() == 0)
            return 0;

        // 2D DP table
        bool dp[s.size()][s.size()] = {false};

        // start with substring of length 1
        // all single char are palindromic on their own
        for(int i = 0; i < s.size(); i++)
            dp[i][i] = true;

        // next, substring of length 2
        for(int i = 0; i < s.size() - 1; i++) {
            if(s[i] == s[i + 1])
                dp[i][i + 1] = true;
        }

        // keep increasing the length of substring
        for(int diff = 2; diff < s.size(); diff++) {
            for(int i = 0; i < s.size() - diff; i++) {
                if(s[i] == s[i + diff] && dp[i+1][i + diff - 1])
                    dp[i][i + diff] = true;
            }
        }

        // count the number of palindromes in the table
        int num_palindromes = 0;
        for(int i = 0; i < s.size(); i++)
            for(int j = 0; j < s.size(); j++)
                if(dp[i][j])
                    num_palindromes += 1;

        return num_palindroms;
    }
};
