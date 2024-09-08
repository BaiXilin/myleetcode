#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
       	// idea: for a valid tree, when starting at any node, BFS traversal should not encounter
		// any node that is already visited before
		// After the traversal is done, all nodes should be visited (it is a connected graph)
		vector<int> visited(n, 0);

		// edge case: graph with no node is a tree
		if(n == 1 && edges.empty())
			return true;

		// BFS traversal starting at first edge
		queue<int> toVisit;
		if(!edges.empty())		// careful for multiple nodes zero edge case
			toVisit.push(edges[0][0]);

		// every edge should only be traversed once
		vector<int> edgeUsed(edges.size(), 0);

		while(!toVisit.empty()) {
			int visiting = toVisit.front();
			toVisit.pop();

			// check if currently visiting node is already visited before
			if(visited[visiting])
				return false;
			else
				visited[visiting] = 1;

			// iterate through all edges to find nodes connected to currently visiting node
			for(int i = 0; i < edges.size(); i++) {
				if(edgeUsed[i])
					continue;

				if(edges[i][0] == visiting) {
					toVisit.push(edges[i][1]);
					edgeUsed[i] = 1;
				}

				if(edges[i][1] == visiting) {
					toVisit.push(edges[i][0]);
					edgeUsed[i] = 1;
				}
			}
		}

		// check if any node has not been visited after the traversal
		for(auto it : visited) {
			if(!it)
				return false;
		}
		
		return true;
    }
};
