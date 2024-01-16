#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // init fast and slow pointer to start from start of vector
        int fast = nums[0], slow = nums[0];

        // move them in the vector as in linked list
        while(true) {
            fast = nums[nums[fast]];
            slow = nums[slow];

            if(fast == slow)
                break;
        }

        // two pointers meet again
        // so they travelled the distance of the cycle
        // reset slow pointer to the start of the list
        slow = nums[0];

        // then move them at the same pace until they meet at the duplicate
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1,3,4,2,2};
    int dup = sol.findDuplicate(nums);

    cout << "dup = " << dup << endl;
}
