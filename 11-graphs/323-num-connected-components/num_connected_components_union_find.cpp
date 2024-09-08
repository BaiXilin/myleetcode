#include <vector>

using namespace std;

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
 		// idea: every node start as one component with parent to itself
		// iterate through all the edges, merge into another component 
		// if they are not already in the same components
		int num_components = n;

		// every node is the parent of itself at the start
		vector<int> parents(n);
		vector<int> ranks(n, 1);	// record num of nodes in a component, enforce order to merge
									//
		for(int i = 0; i < n; i++)
			parents[i] = i;

		// iterate through edges
		for(auto edge : edges) {
			int parent_a = find_parent(edge[0], parents);
			int parent_b = find_parent(edge[1], parents);

			// check if a and b are already in the same connected component
			if(parent_a == parent_b)
				continue;	// don't decrease num_components as no merge is performed

			// merge the one with smaller rank to the one with higher rank
			// both points to the same root parent
			num_components -= 1;
			if(ranks[parent_a] < ranks[parent_b]) {
				// merge a into b
				ranks[parent_b] += ranks[parent_a];
				parents[parent_a] = parent_b;
			} else {
				// merge b into a
				ranks[parent_a] += ranks[parent_b];
				parents[parent_b] = parent_a;
			}
		}
		
		return num_components;
    }

	// iteratively find the root parent of a node
	int find_parent(int node, vector<int>& parents) {
		int res = node;

		while(res != parents[res])
			res = parents[res];

		return res;
	}
};
