#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        // consider at index i
        // water can be trapped at index if both maximum on left and right side are higher than i
        // the amount trapped is min(max_height_left, max_height_right) - height[i]
        
        // 1. one pass to find left maximum to every index
        vector<int> left_maxs(height.size());
        int left_maximum = 0;
        for(int i = 0; i < height.size(); i++) {
            if(height[i] >= height[left_maximum]) {
                left_maximum = i;
            }
            left_maxs[i] = left_maximum;
        }

        // 2. one pass to find right maximum to every index
        vector<int> right_maxs(height.size());
        int right_maximum = height.size() - 1;
        for(int i = height.size() - 1; i >= 0; i--) {
            if(height[i] >= height[right_maximum]) {
                right_maximum = i;
            }
            right_maxs[i] = right_maximum;
        }

        int trapped_water = 0;
        // 3. one pass to calculate rain water trapped at each index
        for(int i = 0; i < height.size(); i++) {
            trapped_water += calculateTrappedWaterAtIndex(height[left_maxs[i]], height[right_maxs[i]], height[i]);
        }
        return trapped_water;
    }

    int calculateTrappedWaterAtIndex(int left_max, int right_max, int height) {
        if(left_max <= height || right_max <= height)
            return 0;
        return minimum(left_max, right_max) - height;
    }

    int minimum(int a, int b) {
        if(a < b) return a;
        return b;
    }
};

int main() {
    Solution sol;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int trapped_water = sol.trap(height);
}
