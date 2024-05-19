class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // container for permutations
        vector<vector<int>> permutations;
        // partial solution of one permutation
        vector<int> permutation;
        // status indicator of if a number is used in partial solution
        unordered_map<int, bool> used;

        permuteHelper(nums, permutation, permutations, used);

        return permutations;
    }

    void permuteHelper(vector<int>& nums, vector<int>& permutation, vector<vector<int>> permutations, unordered_map<int, bool> used) {
        // termination condition: all numbers included in this permutation
        if(permutation.size() == nums.size()) {
            permutations.push_back(permutation);
            return;
        }

        // permutation would include all numbers, so traverse nums
        for(auto& it : nums) {
            // check if this number has already be used
            if(used[it])
                continue; // don't use again

            // add this number to solution
            permutation.push_back(it);
            used[it] = true;

            // incrementally build permutation
            permuteHelper(nums, permutation, permutations, used);

            // restore
            permutation.pop_back();
            used[it] = false;
        }
    }
};
