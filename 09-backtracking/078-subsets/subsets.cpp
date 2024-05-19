class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // initialize the container for the results
        vector<vector<int>> results;

        // indicates partial status (if a num is selected to be in subset)
        vector<bool> numSelectors;

        subsets_helper(nums, numSelectors, results);

        return results;
    }

    void subsets_helper(vector<int>& nums, vector<bool>& numSelectors, vector<vector<int>>& results) {
        // termination condition: selection done on every number
        if(numSelectors.size() == nums.size()) {
            // convert numSelectors into a subset
            vector<int> subset;
            for(int i = 0; i < numSelectors.size(); i++) {
                if(numSelectors[i])
                    subset.push_back(nums[i]);
            }
            results.push_back(subset);
            return;
        }

        // recursively increment the partial solution (numSelectors)
        // case 1: the current number is selected
        numSelectors.push_back(true);
        subsets_helper(nums, numSelectors, results);
        // need to restore the partial solution first
        numSelectors.pop_back();

        // case 2: the current number is not selected
        numSelectors.push_back(false);
        subsets_helper(nums, numSelectors, results);
        numSelectors.pop_back();

        return;
    }
};
