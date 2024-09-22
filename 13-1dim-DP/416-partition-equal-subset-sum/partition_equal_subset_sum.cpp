#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // idea: this question is effectively "subset equal to k"
        //       for every index, it can be in or not in the subset
        //       use memo: memo[index][remaining sum] = memo[index+1][remaining sum]
        //                                          or= memo[index+1][remaining sum - num[index]]
        //                 memo[any index][0] = true
        //                 memo[end of nums][remaining sum] = false
        //
        //       To move from memo to DP:
        //       notice that memo only uses data from last row, can reduce to two rows
        //       notice that memo only uses data from left side, can reduce to one row
        //        - but need to move from right to left to avoid overwrite conflict

        // calculate the total sum
        int total_sum = 0;
        for(auto num : nums)
            total_sum += num;

        // the sum of each subset must be half of that sum
        // this means if total sum is odd, can't divide into two halves
        if(total_sum % 2 == 1)
            return false;
        int half_sum = total_sum / 2;

        // init the 1D dp array
        // starting end-of-nums index, where all except first slot is false
        vector<int> dp(half_sum + 1, 0);
        dp[0] = 1;

        for(int index = nums.size() - 1; index >= 0; index--) {
            for(int remaining = half_sum; remaining >= 0; remaining--) {
                // if remaining sum is smaller than current number, can't pick this number
                if(remaining < nums[index])
                    dp[remaining] = dp[remaining];
                else
                    // choose between pick and not pick
                    dp[remaining] = (dp[remaining] || dp[remaining - nums[index]])
            }
        }

        return dp.back();
    }
};
