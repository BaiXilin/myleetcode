#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // convert prerequistites into a prereq graph of adj list form
		vector<vector<int>> prereqGraph(numCourses);
		for(int course = 0; course < prerequisites.size(); course++)
			prereqGraph[prerequisites[course][0]].push_back(prerequisites[course][1]);

		// we want to detect cycle to determine if it is possible to take all courses
		// AND conclude an ordering of taking the courses
		// Idea: still perform cycle detection with DFS
		// note that the directed graph is (course -> prereq)
		// a DFS will stop at a course that has no prereq, add it to ordering
		// then on unwinding recursive stack, add courses to ordering

		vector<int> courseOrder;
		unordered_map<int, bool> visited;
		bool cycleExists = false;
		for(int i = 0; i < numCourses; i++) {
			// perform DFS on nodes unvisited
			unordered_map<int, bool> recStack;	// remember the nodes visited in this DFS
			if(!visited[i])
				cycleExists = dfs(prereqGraph, visited, recStack, courseOrder, i);
			if(cycleExists) {
				courseOrder.clear();	// return empty ordering if cycle exists	
				break;
			}
		}
		
		return courseOrder;
	}

	bool dfs(vector<vector<int>>& prereqGraph, unordered_map<int, bool>& visited,
			unordered_map<int, bool>& recStack, vector<int>& courseOrder, int i) {
		// check if this node has been visited in this traversal
		if(recStack[i])
			return true;
		// stop traversing if reached a node visited by other traversals
		if(visited[i])
			return false;

		// mark this node as visited
		visited[i] = true;
		recStack[i] = true;

		// traverse all neighbors
		for(auto& prereq : prereqGraph[i]) {
			if(dfs(prereqGraph, visited, recStack, courseOrder, prereq))
				return true;
		}

		// done traversing all neighbors (all prereqs taken)
		courseOrder.push_back(i);
		recStack[i] = false;

		return false;
	}
};

int main() {
	Solution sol;
	vector<vector<int>> prerequisites = {{1, 0}};
	auto order = sol.findOrder(2, prerequisites);
	for(auto& i : order)
		cout << i << " ";
	cout << endl;
}
