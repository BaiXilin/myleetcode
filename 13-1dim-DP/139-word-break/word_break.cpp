#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // idea: maintain a 1D DP array
        //       dp[i] represents s at i-th index has a valid segmentation
        //       dp[i] = true if dp[i-len of a word] == true and s[i-len:i] match the word

        // edge case: empty string has no valid segmentation
        if(s.empty())
            return 0;

        // init the 1D DP array
        vector<int> dp(s.size(), 0);

        // iterate through every char of s
        for(int i = 0; i < s.size(); i++) {
            // for every index i, check if DP condition is satisfied
            for(auto word : wordDict) {
                // skip if index is not long enough for word
                if(word.size() > i + 1)
                    continue;

                if(s.substr(i + 1 - word.size(), word.size()) == word
                    // check if the word matches the prefix of s
                    if(i == word.size() - 1) {
                        dp[i] = 1;
                        break;  // one match is enough
                    } else if(dp[i - word.size()]) {
                        // this condition won't be satisfied if word matches str prefix
                        dp[i] = 1;
                        break;
                    }
                }
            }
        }

        return dp.back();
    }
};
