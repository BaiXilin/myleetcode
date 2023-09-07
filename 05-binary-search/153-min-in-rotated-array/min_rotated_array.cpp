#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int startPtr = 0, endPtr = nums.size() - 1;
        int middlePtr;
        while(startPtr <= endPtr) {
            middlePtr = (startPtr + endPtr) * 1.0 / 2;

            if(nums[startPtr] < nums[(startPtr + nums.size() - 1) % nums.size()]) {
                middlePtr = startPtr;
                break;
            }

            if(nums[middlePtr] < nums[startPtr]) {
                // meaning the minimum is at middlePtr or between startPtr and middlePtr
                endPtr = middlePtr;
            } else if(nums[middlePtr] > nums[startPtr]){
                // nums increasing between startPtr and middlePtr
                // the minimum is at the other half
                startPtr = middlePtr;
            } else {
                // startPtr == middlePtr
                // we have narrowed the search down to two elements
                // the smaller of the two is the minimum
                middlePtr = (nums[startPtr] < nums[endPtr]) ? startPtr : endPtr;
                break;
            }
        }
        return nums[middlePtr];
    }
};

int main() {
    Solution sol;

    vector<int> nums = {3,4,5,1,2}; // expects 1
    //vector<int> nums = {4,5,6,7,0,1,2}; // expects 1
    //vector<int> nums = {11,13,15,17}; // expects 0
    int result = sol.findMin(nums);
    cout << "result = " << result << endl;
}
