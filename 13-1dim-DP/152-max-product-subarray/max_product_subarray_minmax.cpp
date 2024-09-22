#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // idea: keep a min and max so far
        //       while iterating through nums, if curr num is negative, swap min and max
        //       update min, max to be min/max of curr num/curr num * prev min/max
        
        // edge case: empty array, product is 0
        if(nums.empty())
            return 0;

        // need to track minProduct, because when encountering a neg num,
        // it could become maxProduct of the current subarray
        int maxProduct = nums[0], minProduct = nums[0];
        // global max product
        int maxResult = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            // when multiplying with a negative number, the sign flips
            if(nums[i] < 0)
                swap(maxProduct, minProduct);

            // should the minmax product subarray be extended to include the current number
            maxProduct = max(nums[i], nums[i] * maxProduct);
            minProduct = min(nums[i], nums[i] * minProduct);

            maxResult = max(maxResult, maxProduct);
        }

        return maxResult;
    }
};
