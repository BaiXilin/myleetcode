#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // first use a binary search that compares the target with the first element of each row
        // to  determine which row the target should belong to
        int leftPtr = 0, rightPtr = matrix.size() - 1;
        int middlePtr;
        int targetRow = 0;
        while(leftPtr <= rightPtr) {
            middlePtr = (leftPtr + rightPtr) / 2;
            // if the target is in the middlePtr row
            if(target >= matrix[middlePtr].front() && target <= matrix[middlePtr].back()) {
                targetRow = middlePtr;
                break;
            }

            if(target < matrix[middlePtr].front()) {
                rightPtr = middlePtr - 1;
            } else {
                leftPtr = middlePtr + 1;
            }
        }

        // second use another binary search to find the target in the row
        leftPtr = 0; rightPtr = matrix[targetRow].size() - 1;
        while(leftPtr <= rightPtr) {
            middlePtr = (leftPtr + rightPtr) / 2;
            if(target == matrix[targetRow][middlePtr])
                return true;
            if(target < matrix[targetRow][middlePtr])
                rightPtr = middlePtr - 1;
            else
                leftPtr = middlePtr + 1;
        }
        return false;
    }
};

int main() {
    Solution sol;

    //vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    //int target = 3; // expects true

    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 13; // expects false
    bool result = sol.searchMatrix(matrix, target);
    cout << "result = " << result << endl;
}
