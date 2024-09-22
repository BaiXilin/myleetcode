#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        // case 1: rob the first house, ignore the last one
        // case 2: don't rob the first house, consider the last one
        //      max loot = max(rob(case 1), rob(case 2))
        // recursive formula: rob(i) = max(rob(i-2)+nums[i], rob(i-1))

        // base case: can't rob a street with no house
        if(nums.empty())
            return 0;

        // recursive case 1:
        int last = nums.back();
        nums.pop_back();
        int loot_case1 = rob_dp(nums);

        // recursive case 2:
        nums.push_back(last);
        nums.erase(nums.begin());   // not robbing the first house
        int loot_case2 = rob_dp(nums);

        return max(loot_case1, loot_case2);
    }

    int rob_dp(vector<int>& nums) {
        // same as in House Robber 1
        int loot_prev1 = 0, loot_prev2 = 0;
        int result;

        for(num : nums) {
            result = max(loot_prev2 + num, loot_prev1);

            loot_prev2 = loot_prev1;
            loot_prev1 = result;
        }

        return result;
    }
};
