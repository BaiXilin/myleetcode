#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // count the occurrance of chars in s1
        unordered_map<char, int> s1_map;
        for(auto ch : s1) {
            s1_map[ch]++;
        }

        // iterate over s2 using slide window
        int leftPtr = 0, rightPtr = 0;
        unordered_map<char, int> part_s2_map;
        while(rightPtr < s2.length()) {
            if(rightPtr - leftPtr == s1.length())
                return true;
            // next char is not in s1, no way it is a permutation
            if(s1_map.find(s2[rightPtr]) == s1_map.end()) {
                part_s2_map.clear();
                rightPtr++;
                leftPtr = rightPtr;
                continue;
            }
            // still in a permutation, keep going
            if(++part_s2_map[s2[rightPtr]] <= s1_map[s2[rightPtr]]) {
                rightPtr++;
            } else {
                // the next char is still in s1, so still possible to be in a permutation
                // slide the window to find out
                part_s2_map[s2[leftPtr]]--;
                leftPtr++;
                part_s2_map[s2[rightPtr]]--;
            }
        }
        if(rightPtr - leftPtr == s1.length())
            return true;
        return false;
    }
};

int main() {
    Solution sol;
    string s1 = "adc", s2 = "dcda";
    //string s1 = "ab", s2 = "eidbaooo";
    bool result = sol.checkInclusion(s1, s2);
    cout << "result = " << result << endl;
}
