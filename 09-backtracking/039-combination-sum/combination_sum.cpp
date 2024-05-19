#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // holding the combinations of candidates that add to target
        vector<vector<int>> results;          
        // partial solution of which numbers are selected
        vector<int> selected;
        // temporary variable to avoid calculating the sum at every level
        int sum = 0;

        combinationSumHelper(candidates, target, sum, 0, selected, results);

        return results;
    }

    void combinationSumHelper(vector<int>& candidates, int target, int& sum, int index, vector<int>& selected, vector<vector<int>>& results) {
        if(sum == target) {
            // a result spotted
            results.push_back(selected);
            return;
        } else if(sum > target) {
            // constraint violated (since no negative candidate, impossible to get target once exceeds it)
            return;
        }
        
        // recursively attempts the next candidate to reach target
        for(int i = index ; i < candidates.size(); i++) {
            selected.push_back(candidates[i]);
            sum += candidates[i];
            combinationSumHelper(candidates, target, sum, i, selected, results);

            // restore partial solution
            selected.pop_back();
            sum -= candidates[i];
        }
    }

};

int main() {
    Solution sol;
    vector<int> input{2, 3, 6, 7};

    auto result = sol.combinationSum(input, 7);

    for(auto it : result) {
        for(auto iit: it)
            cout << iit << " ";
        cout << endl;
    }
}
