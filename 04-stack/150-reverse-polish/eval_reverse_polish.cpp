#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num_stack;
        int result;

        for(auto &it : tokens) {
            if(it == "+" || it == "-" || it == "*" || it == "/") {
                char symbol = it[0];
                int num1 = num_stack.top();
                num_stack.pop();
                int num2 = num_stack.top();
                num_stack.pop();
                int result = 0;
                switch(symbol) {
                case '+':
                    num_stack.push(num1 + num2);
                    break;
                case '-':
                    num_stack.push(num2 - num1);
                    break;
                case '*':
                    num_stack.push(num1 * num2);
                    break;
                case '/':
                    num_stack.push(num2 / num1);
                    break;
                }
            } else {
                // input is a number. push to stack
                num_stack.push(stoi(it));
            }
        }
        return num_stack.top();
    }
};
