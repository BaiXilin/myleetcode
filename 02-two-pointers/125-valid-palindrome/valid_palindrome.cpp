#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution {
    public:
        bool isPalindrome(string s) {
            // formated string
            string fs;
            for(int i = 0; i < s.length(); i++) {
                if(isAlphaNumeric(s[i])) fs.append(1, tolower(s[i]));
            }
            
            cout << "formated string is " << fs << endl;

            for(int i = 0; i < fs.length()/2; i++) {
                if(fs[i] != fs[fs.length()-1-i]) return false;
            }

            return true;
        }

        bool isAlphaNumeric(char c) {
            if(c - '0' >= 0 && c - '0' <= 9) return true;
            if(c - 'a' >= 0 && c - 'a' < 26) return true;
            if(c - 'A' >= 0 && c - 'A' < 26) return true;
            return false;
        }
};

int main() {
    Solution sol;
    //string s = "A man, a plan, a canal: Panama";
    string s = "a_ba";
    bool isPalindrome = sol.isPalindrome(s);
    if(isPalindrome)
        cout << "the string is palindrome" << endl;
    else
        cout << "the string is not palindrome" << endl;
}
