#include <deque>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> window;

        for(int i = 0; i < k; i++) {
            if(window.empty()) {
                window.push_back(i);
                continue;
            }
            while(!window.empty() && nums[i] >= nums[window.back()])
                window.pop_back();
            window.push_back(i);
        }

        int leftPtr = 0, rightPtr = k - 1;
        while(rightPtr < nums.size()) {
            if(leftPtr > window.front())
                window.pop_front();
            while(!window.empty() && nums[rightPtr] >= nums[window.back()])
                window.pop_back();
            window.push_back(rightPtr);
            result.push_back(nums[window.front()]);

            leftPtr++;
            rightPtr++;
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = sol.maxSlidingWindow(nums, 3);

    for(auto it : result) {
        cout << it << " ";
    }
    cout << endl;
}
