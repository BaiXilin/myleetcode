#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int leftPtr = 0, rightPtr = nums.size() - 1;
        int middlePtr;

        while(leftPtr <= rightPtr) {
            middlePtr = (leftPtr + rightPtr) / 2;

            if(nums[middlePtr] == target) // found
                return middlePtr;

            if(nums[leftPtr] <= nums[middlePtr]) {
                // the array is sorted in [leftPtr, middlePtr)
                if(nums[leftPtr] <= target && target < nums[middlePtr])
                    // target in sorted first half
                    rightPtr = middlePtr - 1;
                else
                    // target in second half
                    leftPtr = middlePtr + 1;
            } else {
                // the array is sorted in (middlePtr, rightPtr]
                if(nums[middlePtr] < target && target <= nums[rightPtr])
                    // target is in sorted second half
                    leftPtr = middlePtr + 1;
                else
                    // target in first half
                    rightPtr = middlePtr - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    //vector<int> nums = {4,5,6,7,0,1,2};
    //int target = 0; // expects 4

    //vector<int> nums = {4,5,6,7,0,1,2};
    //int target = 3; // expects -1 
    
    //vector<int> nums = {1};
    //int target = 0; // expects -1 

    vector<int> nums = {3, 1};
    int target = 1;

    int result = sol.search(nums, target);
    cout << "result = " << result << endl;
}
