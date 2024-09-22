#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // idea: keep an 1D DP array
        //       For example, coins=[1,2,5], for amount i, dp[i]= min(dp[i-1], dp[i-2], dp[i-5]) + 1
        //       dp[i] represents the min number of coins to reach amount i

        // edge case: 0 coins needed for amount 0
        if(amount == 0)
            return 0;

        // init the DP array
        vector<int> dp(amount, -1);

        // amounts equal to amount of a coin has a min of 1 way to be reached
        for(auto coin : coins)
            if(coin <= amount)
                dp[coin - 1] = 1;

        for(int i = 0; i < amount; i++) {
            // 1 is the guaranteed way to reach an amount, no need to do anything else
            if(dp[i] == 1)
                continue;

            // find the min ways by examing past dp entries
            int min = INT_MAX;
            for(auto coin : coins) {
                // is i big enough to exam coin?
                if(i < coin - 1)
                    continue;

                if(dp[i - coin] == -1)
                    continue;

                if(dp[i - coin] < min)
                    min = dp[i - coin];
            }

            // no way to reach this amount
            if(min == INT_MAX)
                continue;

            dp[i] = min + 1;    // need one extra coin
        }

        return dp.back();
    }
};
