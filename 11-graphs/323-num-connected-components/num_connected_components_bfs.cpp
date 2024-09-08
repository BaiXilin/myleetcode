#include <list>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
       	// idea: start BFS on edges until no more nodes can be traversed
		// this counts as one components
		// repeat the process until no more unvisited node exists
		
		// notice that edges are given: convert to adj list for faster access
		vector<list<int>> adj_list(n);
		for(auto edge : edges) {
			adj_list[edge[0]].push_back(edge[1]);
			adj_list[edge[1]].push_back(edge[0]);
		}

		int numComponents = 0;
		vector<int> visited(n, 0);
		queue<int> toVisit;

		// need to perform one BFS on every connected component
		while(true) {
			// until no more unvisited nodes
			for(int i = 0; i < n; i++) {
				if(!visited[i]) {
					toVisit.push(i);
					break;
				}
			}

			if(toVisit.empty())
				break;
			numComponents++;

			// BFS traversal starting from one node
			while(!toVisit.empty()) {
				int visiting = toVisit.front();
				toVisit.pop();

				visited[visiting] = 1;

				// add all currently visiting node's neighbors to the queue
				// exclude those already viisited
				for(auto iter : adj_list[visiting]) {
					if(!visited[iter])
						toVisit.push(iter);
				}
			}
		}

		return numComponents;
    }
};
