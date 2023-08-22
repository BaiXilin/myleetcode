#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // construct a map for the pattern t
        unordered_map<char, int> t_chars;
        int minLength = s.length(), minStrLeft = 0, minStrRight = 0;

        for(auto ch : t) {
            t_chars[ch]++;
        }

        // using the slide window tech
        int leftPtr = 0, rightPtr = 0;
        unordered_map<char, int> s_chars;
        while(rightPtr < s.length()) {
            s_chars[s[rightPtr]]++;
            if(SIncludesT(t_chars, s_chars)) {
                if(minLength >= rightPtr - leftPtr + 1) {
                    minLength = rightPtr - leftPtr + 1;
                    minStrLeft = leftPtr;
                    minStrRight = rightPtr+1;
                }
                // propogate leftPtr until at the next char in t
                s_chars[s[leftPtr]]--;
                leftPtr++;
                while(leftPtr < s.length() && t_chars.find(s[leftPtr]) == t_chars.end()) {
                    s_chars[s[leftPtr]]--;
                    leftPtr++;
                }
                s_chars[s[rightPtr]]--;
            } else {
                rightPtr++;
            }
        }
        
        if(SIncludesT(t_chars, s_chars)) {
            if(minLength >= rightPtr - leftPtr + 1) {
                minLength = rightPtr - leftPtr + 1;
                minStrLeft = leftPtr;
                minStrRight = rightPtr+1;
            }
        }

        if(minStrLeft == minStrRight) return "";
        return s.substr(minStrLeft, minLength);
    }

    bool SIncludesT(unordered_map<char, int>& t_chars, unordered_map<char, int>& s_chars) {
        for(auto &it : t_chars) {
            if(s_chars[it.first] < it.second)
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    //string s = "ADOBECODEBANC", t = "ABC";
    string s = "ab", t = "b";
    string result = sol.minWindow(s, t);
    cout << "result = " << result << endl;
}
