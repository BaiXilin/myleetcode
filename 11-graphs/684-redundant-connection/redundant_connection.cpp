#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       	// idea: union find, return the first edge that connects two already-connected nodes
		//
		// first, find the number of nodes
		int n = 0;
		for(auto edge : edges) {
			if(edge[0] > n)
				n = edge[0];
			if(edge[1] > n)
				n = edge[1];
		}

		// data structure needed for union find
		vector<int> ranks(n, 1);// every component starts with one node
		vector<int> parents(n);	// every node starts as their own parent
		for(int i = 0; i < n; i++)
			parents[i] = i;

		for(auto edge : edges) {
			int parent_a = find(edge[0], parents);
			int parent_b = find(edge[1], parents);

			// if two nodes are already connected
			if(parent_a == parent_b)
				return edge;

			// merge the two nodes using rank-order
			merge(parent_a, parent_b, parents, ranks);
		}
    }

	int find(int node, vector<int>& parents) {
		while(node != parents[node])
			node = parents[node];
		
		return node;
	}

	void merge(int a, int b, vector<int>& parents, vector<int>& ranks) {
		if(ranks[a] < ranks[b]) {	// merge a into b
			ranks[b] += ranks[a];
			parents[a] = parents[b];
		} else {					// merge b into a
			ranks[a] += ranks[b];
			parents[b] = parents[a];
		}
	}
};
