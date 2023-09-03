#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        stack<char> par_stack;

        generateParenthesisHelper(n, result, par_stack, 0, 0);
        
        return result;
    }

    void generateParenthesisHelper(int n, vector<string>& result, stack<char> par_stack, int num_open, int num_close) {
        // base case: running out of opening parenthese
        //  so we append the missing closing parenthesis and record the string
        if(num_open == n) {
            // fill the missed closing parenthesis
            while(num_close < n) {
                par_stack.push(')');
                num_close++;
            }
            // get all symbols out of the stack. Since stack, order is reversed
            string reverse_str;
            while(!par_stack.empty()) {
                reverse_str += par_stack.top();
                par_stack.pop();
            }
            // correct the ordering
            string result_str;
            for(int i = 0; i < reverse_str.size(); i++)
                result_str += reverse_str[reverse_str.size() - 1 - i];
            result.push_back(result_str);
            return;
        }

        // recursive caes 1: 
        //  has an equal number of opening and closing parenthesis, so only an opening parenthesis is allowed
        if(num_open == num_close) {
            par_stack.push('(');
            generateParenthesisHelper(n, result, par_stack, num_open + 1, num_close);
            return;
        }
        // recursive case 2:
        //  both parenthesis are allowed
        par_stack.push('(');
        generateParenthesisHelper(n, result, par_stack, num_open + 1, num_close);
        par_stack.pop();
        par_stack.push(')');
        generateParenthesisHelper(n, result, par_stack, num_open, num_close + 1);
        return;
    }
};

int main() {
    Solution sol;
    int n = 4;
    
    auto result = sol.generateParenthesis(n);
    for(auto &it : result)
        cout << it << ", ";
    cout << endl;
}
