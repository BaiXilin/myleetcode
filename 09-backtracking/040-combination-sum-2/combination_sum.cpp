class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // duplicate numbers possible
        sort(candidates.begin(), candidates.end());

        // container for combinations sums result
        vector<vector<int>> combinationSums;
        // container for partial solution
        vector<int> partialSum;

        backTrackCombinationSum(candidates, target, partialSum, 0, 0, combinationSums);

        return combinationSums;
    }

    void backTrackCombinationSum(vector<int>& candidates, int target, vector<int>& partialSum, int sum, int numCandidates, vector<vector<int>>& combinationSums) {
        // termination case: when sums to target
        if(sum == target) {
            combinationSums.push_back(partialSum);
            return;
        } else if(sum > target || numCandidates >= candidates.size()) {
            return;
        }

        // for every unique number in candidates, use it [0, num of occurrence] times in the combination sum
        partialSum.push_back(candidates[numCandidates]); // [1, numOccurrence case]
        backTrackCombinationSum(candidates, target, partialSum, sum + candidates[numCandidates], numCandidates + 1, combinationSums);

        // restore partial solution
        partialSum.pop_back();

        // consider not using this unique number
        while(numCandidates + 1 < candidates.size() && candidates[numCandidates] == candidates[numCandidates + 1])
            numCandidates++;
        backTrackCombinationSum(candidates, target, partialSum, sum, numCandidates + 1, combinationSums);
    }
};
