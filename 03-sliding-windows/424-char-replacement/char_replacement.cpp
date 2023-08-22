#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int leftPtr = 0, rightPtr = 0;
        int windowSize = 0;
        vector<int> chars(26, 0);

        while(rightPtr < s.length()) {
            chars[s[rightPtr] - 'A']++;
            if(windowSize - findMostFreqChar(chars) < k) {
                windowSize++;
                rightPtr++;
            } else {
                // not enough replacement for the current window size
                // shift window one slot to the right
                chars[s[leftPtr] - 'A']--;
                leftPtr++;
                rightPtr++;
            }
        }
        return windowSize;
    }

    int findMostFreqChar(vector<int>& chars) {
        int mostFreqIndex = 0;
        for(int i = 0; i < chars.size(); i++) {
            if(chars[i] > chars[mostFreqIndex])
                mostFreqIndex = i;
        }
        return chars[mostFreqIndex];
    }
};

int main() {
    Solution sol;
    string s = "AABABBA";
    int k = 1;
    int result = sol.characterReplacement(s, k);
    cout << "result = " << result << endl;
}
