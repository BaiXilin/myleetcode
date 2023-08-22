#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int iter1 = 0, iter2 = height.size() - 1;
        int max_area = 0, temp_area = 0;
        while(iter1 < iter2) {
            temp_area = calculateArea(height, iter1, iter2);
            if(temp_area > max_area) max_area = temp_area;

            // I am being greedy...
            if(height[iter1] < height[iter2]) {
                iter1++;
            } else {
                iter2--;
            }
        }
        return max_area;
    }

    int calculateArea(const vector<int>& height, int i, int j) {
        int smaller_height = height[i] < height[j] ? height[i] : height[j];
        int width = (i < j) ? (j-i) : (i-j);
        return smaller_height * width;
    }
};
