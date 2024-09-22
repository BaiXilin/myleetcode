#include <vector>
#include <algorithm>
#include <priority_queue>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // idea:
        //  Part 1: 1D DP
        //      Maintain an array, dp[i] represents the longest subseq at index i
        //      dp[i] = max(dp[j] + 1) for all j < i && nums[j] < nums[i]
        //      "For a new number, should I use it or not in the subseq"
        //  Part 2: Smarter subseq
        //      Part 1 requires a linear search for every number
        //      If sub can't be expanded to include nums[i], replace the first num in sub
        //      that is larger than nums[i]. The length of sub is the same, and we have 
        //      more opportunity for future expansion (replaced with the smaller nums[i])
        //  Part 3: Faster search in subseq
        //      since nums in existing subseq are sorted, use binary search for logn time

        // init DP array
        // init all slots to value of 1 b/c they are a subseq by themselves
        vector<int> dp(nums.size(), 1);
        
        // create list for longest increasing subseq
        vector<int> lis;

        // in the worst case, subseq length = nums length
        // reserve space to avoid realloc
        lis.reserve(nums.size());

        // special: the first number belongs to the subseq initially
        lis.push_back(nums[0]);

        for(int i = 1; i < nums.size(); i++) {
            binarySearchAndReplace(lis, nums[i]);
            dp[i] = lis.size();
        }

        return lis.size();
    }

    void binarySearchAndReplace(vector<int>& lis, int num) {
        // using binary search to find lis[i] where lis[i-1] < num < lis[i]
        // if such an i is found, replace lis[i] with num
        // if not, append num to lis 
        
        if(num > lis.back()) {
            lis.push_back(num);
            return;
        }

        int left = 0, right = lis.size();
        int middle;
        while(left < right) {
            middle = (left + right) / 2;
            // we are looking for strictly increasing subseq, if equal, do nothing
            if(num == lis[middle])
                return;
            
            if(num < lis[middle])
                right = middle;
            else
                left = middle + 1;
        }

        lis[left] = num;        
        return;
    }
};
