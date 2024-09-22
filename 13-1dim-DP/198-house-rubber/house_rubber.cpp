#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        // recursive case: when facing a house, two options:
        //  a) rob the house, and get all cumulative loots from house i-2
        //  b) don't rob the house, and get all cumulative loots from house i-1
        //      so the recursive formula is rob(i)=max(i+rob(i-2), rob(i-1))

        // so only need need to remember rob(i-2) and rob(i-1)
        // also don't need recursion
        
        // base case: can't rob a street with no house
        if(nums.empty())
            return 0;

        int rob_prev2 = 0;
        int rob_prev1 = 0;
        int result;

        for(auto num : nums) {
            result = max(num + rob_prev2, rob_prev1);

            // update the prevs
            int tmp = rob_prev1;
            rob_prev1 = result;
            rob_prev2 = tmp;
        }

        return result;
    }
};
