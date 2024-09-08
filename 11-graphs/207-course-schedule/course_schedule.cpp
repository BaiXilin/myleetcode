#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		// Note: numCourses is the number of courses in prerequisites
       	// construct a directed graph based on prerequisites
		vector<vector<int>> prereqGraph(numCourses);
		for(int r = 0; r < prerequisites.size(); r++) {
			// prerequistites[r] = {ai, bi}. bi is needed to take ai
			int prereqCourse = prerequisites[r][1];
			int targetCourse = prerequisites[r][0];
			prereqGraph[targetCourse].push_back(prereqCourse);
		}

		// then perform DFS search to direct cycle
		// if cycle exists -> not possible to take numCourses
		// to detect cycle, remember all courses already taken
		unordered_map<int, bool> visited;
		for(int i = 0; i < numCourses; i++) {
			unordered_map<int, bool> recStack;	// record the nodes visited in this DFS
			bool cycleExists = cycleDetectionDfs(prereqGraph, visited, recStack, i);
			if(cycleExists)
				return false;
		}
		return true;
    }

	bool cycleDetectionDfs(vector<vector<int>>& prereqGraph, unordered_map<int, bool>& visited,
			unordered_map<int, bool>& recStack, int i) {
		// see if this node has been visited before
		if(visited[i])
			return false;

		// visited course i
		visited[i] = true;
		recStack[i] = true;	

		// check for cycle
		for(int c = 0; c < prereqGraph[i].size(); c++) {
			if(recStack[prereqGraph[i][c]])
				return true;
			if(cycleDetectionDfs(prereqGraph, visited, recStack, prereqGraph[i][c]))
				return true;
		}

		recStack[i] = false;

		return false;
	}
};
