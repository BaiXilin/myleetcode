#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef struct rectangle {
        int index;
        int height;
    } rectangle;

    int largestRectangleArea(vector<int>& heights) {
        vector<rectangle> rectStack;
        int maxArea = 0;
        
        for(int i = 0; i < heights.size(); i++) {
            int startIndex = i;
            while(!rectStack.empty() && heights[i] < rectStack.back().height) {
                // there is a smaller height rectangles coming
                // pop the rectangles that can no longer be expanded due to the smaller height
                // need to check if they have larger sizes
                maxArea = max(maxArea, rectStack.back().height * (i - rectStack.back().index));
                // after popped rects that cannot be expanded, we arrived at rects that can be expanded
                // record its starting index
                startIndex = rectStack.back().index;
                rectStack.pop_back();
            }
            // rectStack remains with increasing heights
            rectStack.push_back({startIndex, heights[i]});
        }
        
        // there are still rectangles in the stack
        // given how the stack is maintained, these rectangles all ends with the rightmost side of histogram
        int rightmostIndex = heights.size();
        while(!rectStack.empty()) {
            maxArea = max(maxArea, rectStack.back().height * (rightmostIndex - rectStack.back().index));
            rectStack.pop_back();
        }
        return maxArea;
    }
};

int main() {
    Solution sol;

    //vector<int> heights = {2,1,5,6,2,3}; // expects 10
    //vector<int> heights = {2, 4};   // expects 4
    vector<int> heights = {2, 1, 2};    // expects 3
    int result = sol.largestRectangleArea(heights);

    cout << "result = " << result << endl;
}
