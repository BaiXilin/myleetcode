class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // first sort the numbers
        sort(nums.begin(), nums.end());

        // container for results
        vector<vector<int>> subsets;
        // container for a partial subset
        vector<int> subset;
        
        subsetsWithDupHelper(nums, subset, 0, subsets);

        return subsets;
    }

    void subsetsWithDupHelper(vector<int>& nums, vector<int>& subset, int subsetLength, vector<vector<int>>& subsets) {
        // termination case: decision made on every number
        if(subsetLength == nums.size()) {
            subsets.push_back(subset);
            return;
        }

        // for every unique number in nums, make a decision to include it [0, numOccurrence] times
        subset.push_back(nums[subsetLength]);  // [1, numOccurrence] covered
        subsetsWithDupHelper(nums, subset, subsetLength + 1, subsets);

        // restore partial solution
        subset.pop_back();

        // cases where the subset does not contain this unique number
        while(subsetLength + 1 < nums.size() && nums[subsetLength] == nums[subsetLength + 1])
            subsetLength++; // skip this unique number
        subsetsWithDupHelper(nums, subset, subsetLength + 1, subsets);
    }
};
