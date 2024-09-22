class Solution {
public:
    int climbStairs(int n) {
        // idea: bottom-up approach is used
        // remember the number of ways to do n-1 and n-2 cases
        int n_sub1 = 2;
        int n_sub2 = 1;

        // base cases, in case n-1 or n-2 is not a valid number
        if(n == 0)
            return 0;
        else if(n == 1)
            return 1;
        else if(n == 2)
            return 2;

	// recursive case starts with n >= 3
        int n_sub0;
        for(int i = 3; i <= n; i++) {
            n_sub0 = n_sub1 + n_sub2;

            // update n-1 and n-2
            n_sub2 = n_sub1;
            n_sub1 = n_sub0;
        }

        return n_sub0;
    }
};
