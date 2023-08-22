// two sum 2: the array is sorted in non-decreasing order
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        auto start = numbers.begin();
        auto end = numbers.end() - 1;

        while(start <= end) {
            int missing = target - *start;
            while(*end > missing)
                end--;
            if(*end == missing) return vector<int>{(int)distance(numbers.begin(), start) + 1, (int)distance(numbers.begin(), end) + 1};
            start++;
        }
        return vector<int>{};
    }
};

int main() {
    Solution sol;
    vector<int> numbers{2,8,9,15,17};
    auto result = sol.twoSum(numbers, 17);
    if(result.size() == 2) {
        cout << result[0] << " " << result[1] << endl;
    }
}
