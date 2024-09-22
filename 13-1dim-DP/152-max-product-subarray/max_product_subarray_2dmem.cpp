// this approach uses n^2 memory and exceeds memory limit
// see minmax approach

#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // idea: Maintain a 2D array of subarray products
        //       Use a sliding window of increasing size to easily computer the product using previous results

        // edge case: empty array, product is 0
        if(nums.empty())
            return 0;

        // init the 2D DP table
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), INT_MIN))

        // every number is the product of itself
        for(int i = 0; i < nums.size(); i++)
            dp[i][i] = nums[i]; // represents max product of subarray [i, j]

        // starting with a sliding window of size 2
        for(int diff = 1; diff < nums.size(); diff++) {
            // slide it through the entire nums array
            for(int i = 0; i < num.size() - diff; i++) {
                dp[i][i + diff] = dp[i][i + diff - 1] * nums[i + diff];
            }
        }

        // find the max from the dp table
        int max = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < nums.size(); j++) {
                if(max > dp[i][j])
                    max = dp[i][j];
            }
        }

        return max;
    }
};
