#include <iostream>
#include <vector>

using namespace std;

// example: nums = [-1, 0, 1, 2, -1, -4]
// return: [-1, 0, 1] and [-1, -1, 2]

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // idea:
        // we know how to do two sum, so divide and conquer
        // note that we only want unique solution sets
        // for every element in nums, try two sums with target as the missing value

        vector<vector<int>> results;
        // sort nums so two sums can be easily computed
        sort(nums.begin(), nums.end());
        
        int i = 0;
        while(i < nums.size()) {
            int missing = 0 - nums[i];
            // two sum to find two values that would add up to 0
            twoSum(results, nums, i, missing);

            // since we only want unique solutions, the we have exhausted
            // solutions that start with nums[i], we can skip all same
            // values in nums
            i++;
            while(i < nums.size() && nums[i-1] == nums[i])
                i++;
        }

        return results;
    }

    void twoSum(vector<vector<int>>& results, const vector<int>& nums, int it, int target) {
        // can't have a result if no enough left
        if(it == nums.size() - 1 || it == nums.size() - 2)
            return;
        
        // two iterators to utilize sorted nums
        int start = it + 1, end = nums.size() - 1;
        while(start < end) {
            int temp = nums[start] + nums[end];
            if(temp == target) {
                results.push_back(vector<int>{nums[it], nums[start], nums[end]});
                start++; end--;
                while(start < end && nums[start] == nums[start-1]) start++;
                while(start < end && nums[end] == nums[end+1]) end--;
            } else if(temp > target){
                end--;
            } else {
                start++;
            }
        }
    }
};
