#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // handle empty array case
        if(nums1.empty())
            return findMedianSortedArray(nums2);
        else if(nums2.empty())
            return findMedianSortedArray(nums1);

        // determine which array is shorter
        // perform binary search on it
        vector<int> A, B;
        if(nums1.size() < nums2.size()) {
            A = nums1;
            B = nums2;
        } else {
            A = nums2;
            B = nums1;
        }

        int totalSize = nums1.size() + nums2.size();
        // the number of elements before the median in merged array
        int numEleBeforeMed = totalSize / 2;

        // left and right controls AMiddle, or where the left partation of A is
        int left = 0, right = A.size() - 1;
        int AMiddle, BMiddle;

        while(true) {
            // set the left partations
            AMiddle = floor((left + right) / 2.0);
            BMiddle = numEleBeforeMed - AMiddle - 2;

            // check if the left partations are correctly set
            // get the number before and after the partation, careful with boundary handling            
            int ALeft = (AMiddle >= 0) ? A[AMiddle] : numeric_limits<int>::min();
            int ARight = (AMiddle + 1 < A.size()) ? A[AMiddle + 1] : numeric_limits<int>::max();
            int BLeft = (BMiddle >= 0) ? B[BMiddle] : numeric_limits<int>::min();
            int BRight = (BMiddle + 1 < B.size()) ? B[BMiddle + 1] : numeric_limits<int>::max();

            // if the current partation is correct, locate the median
            if(ALeft <= BRight && BLeft <= ARight) {
                if(totalSize % 2 == 1)
                    return min(ARight, BRight);
                else
                    return (max(ALeft, BLeft) + min(ARight, BRight)) / 2.0;
            }

            // if not, we need to update left & right of nums1
            if(ALeft > BRight) {
                // left partation of A is too large
                right = AMiddle - 1;
            } else {
                // BLeft > ARight
                // left partation of A is too small
                left = AMiddle + 1;
            }
        }
        return -1;
    }

    double findMedianSortedArray(vector<int>& nums) {
        // guanarteed: nums not empty
        if(nums.size() % 2 == 1)
            return nums[nums.size() / 2];
        return (nums[nums.size() / 2] + nums[nums.size() / 2 - 1]) * 1.0 / 2;
    }
};

int main() {
    Solution sol;

    //vector<int> nums1 = {1,4,5,8,9,10};
    //vector<int> nums2 = {2,3,6,7,11}; // expects 6.000
    
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};
    
    double result = sol.findMedianSortedArrays(nums1, nums2);
    cout << "result = " << result << endl;
}
