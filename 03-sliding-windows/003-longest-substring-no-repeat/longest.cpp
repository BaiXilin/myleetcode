#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0, length = 1;
        int leftPtr = 0, rightPtr = 1;
        unordered_map<char, bool> characters;
        characters[s[leftPtr]] = true;

        while(rightPtr < s.length()) {
            if(characters.find(s[rightPtr]) != characters.end()) {
                // a repeating character is found
                characters.erase(s[leftPtr]);
                leftPtr++;
                length--;
            } else {
                // not a repeating character
                characters[s[rightPtr]] = true;
                length++;
                rightPtr++;
            }
            if(maxLength < length)
                maxLength = length;
        }
        return maxLength;
    }
};

int main() {
    Solution sol;
    string s = "abca";
    int result = sol.lengthOfLongestSubstring(s);
    cout << "result = " << result << endl;
}
