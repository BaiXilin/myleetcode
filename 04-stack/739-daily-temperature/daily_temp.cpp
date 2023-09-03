#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> temp_stack;

        // idea: start from the end of vector
        // push the index of temp into the stack
        // keep the stack monotonic increasing
        // so that every slot has the next warmer temp in the next slot
        for(int i = temperatures.size() - 1; i >= 0; i--) {
            while(!temp_stack.empty() && temperatures[i] >= temperatures[temp_stack.top()]) {
                temp_stack.pop();
            }
            if(temp_stack.empty()) {
                temp_stack.push(i);
                result[i] = 0;
            } else {
                result[i] = temp_stack.top() - i;
                temp_stack.push(i);
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> temps = {73,74,75,71,69,72,76,73};
    auto results = sol.dailyTemperatures(temps);

    for(auto it : results)
        cout << it << " ";
    cout << endl;
}
