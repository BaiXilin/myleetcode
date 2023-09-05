#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int leftPtr = 0;
        int rightPtr = nums.size() - 1;
        int middlePtr;

        while(leftPtr <= rightPtr) {
            middlePtr = (leftPtr + rightPtr) / 2;

            if(nums[middlePtr] == target)
                return middlePtr;
            if(nums[middlePtr] < target) {
                leftPtr = middlePtr + 1;
            } else {
                rightPtr = middlePtr - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    //vector<int> nums = {-1,0,3,5,9,12};
    //int target = 9; // expects 4

    vector<int> nums = {-1,0,3,5,9,12};
    int target = 2; // expects -1
    int result = sol.search(nums, target);

    cout << "result = " << result << endl;
}
