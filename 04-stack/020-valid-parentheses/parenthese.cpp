#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> symbols;
        for(auto it : s) {
            if(it == '(' || it == '[' || it == '{')
                symbols.push(it);
            else {
                if(symbols.empty())
                    return false;
                char top = symbols.top();
                symbols.pop();
                if(!match(top, it))
                    return false;
            }
        }
        if(!symbols.empty())
            return false;
        return true;
    }
    
    bool match(char top, char it) {
        if(top == '(' && it == ')')
            return true;
        if(top == '[' && it == ']')
            return true;
        if(top == '{' && it == '}')
            return true;
        return false;
    }
};

int main() {
    Solution sol;
    string s = "()[]{}";
    bool result = sol.isValid(s);

    cout << "result = " << result << endl;
}
