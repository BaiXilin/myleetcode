#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // idea: use bottom-up DP
	// for non-base step k, min cost = min(cost to k-1, cost to k-2) + cost of k    
	
	// base case: only two stairs    
	if(cost.size() == 2)
	    return min(cost[0], cost[1]);

	// recursive case starts with number of stairs >= 3
	cost.push_back(0);

	pair<int, int> prev_min_costs(cost[0], min(cost[0], cost[1]));
	int min_cost;
	for(int i = 2; i < cost.size(); i++) {
	    min_cost = min(prev_min_costs.first, prev_min_costs.second) + cost[i];

	    // move forward and update prev_min_costs
	    prev_min_costs.first = prev_min_costs.second;
	    prev_min_costs.second = min_cost;
	}

	return min_cost;
    }
};
