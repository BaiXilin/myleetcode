#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        // idea: DP nums[i] = nums[i-1]+nums[i-2]
        //       But many special cases
        //       1. first char is a 0, invalid decoding
        //       2. non-first char is a 0, and prev char is a 1/2: nums[i] = nums[i-2]+0
        //       3. non-first char is a 0, and prev char is not a 1/2: invalid decoding
        //       4. current char is 7/8/9, and prev char is 2: nums[i] = nums[i-1]+0
        //       5. prev char is 3-9: nums[i] = nums[i-1]+0

        // edge case: empty string has only one way of decoding
        if(s.empty())
            return 0;

        // the first char is a special case due to '0'
        if(s[0] == '0') // case 1
            return 0;
        if(s.size() == 1)
            return 1;

        int num_prev1 = 1, num_prev2 = 1;

        // bottom-up DP
        int result = 0;
        for(int i = 1; i < s.size(); i++) {
            // check for invalid '0' (case 3)
            if(s[i] == '0' && !(s[i-1] == '1' || s[i-1] == '2'))
                return 0;

            // check for valid '0' (case 2)
            if(s[i] == '0' && (s[i-1] == '1' || s[i-1] == '2')) {
                result = num_prev2;
                num_prev2 = 0;
                num_prev1 = result;
            } else if((s[i] >= '7' && s[i] <= '9' && s[i-1] == '2')
                || (s[i-1] >= '3' && s[i-1] <= '9')) {
                // case 4 and 5
                result = num_prev1;
                num_prev2 = num_prev1;
                num_prev1 = result;
            } else {
                // general case
                result = num_prev2 + num_prev1;
                num_prev2 = num_prev1;
                num_prev1 = result;
            }
        }

        return result;
    }
};
