#include <vector>
#include <string>
#include <unordered_map>
#include <list>
#include <queue>
#include <utility>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		// idea: construct a graph using words in the wordList
		// 		where two words are neighbors if they differ in only one letter
		// 		Then, using a BFS to find the shortest path from beginWord to endWord
		
		// contruct the graph
		// determine the number of nodes (unique words), note that beginWord may not in wordList
		int numWords = 0;
		bool foundBeginWord = false;
		for(auto word : wordList)
			if(word == beginWord) {
				foundBeginWord = true;
				break;
			}
		
		if(!foundBeginWord)
			wordList.push_back(beginWord);
		numWords = wordList.size();

		// graph stored using adj list
		unordered_map<string, list<string>> adjList;
		for(int i = 0; i < numWords; i++) {
			for(int j = i + 1; j < numWords; j++) {
				int numDiffChars = 0;
				for(int chIndex = 0; chIndex < wordList[i].length(); chIndex++) {
					if(wordList[i][chIndex] != wordList[j][chIndex])
						numDiffChars += 1;
					if(numDiffChars > 1)
						break;
				}

				if(numDiffChars == 1) {
					adjList[wordList[i]].push_back(wordList[j]);
					adjList[wordList[j]].push_back(wordList[i]);
				}
			}
		}

		// perform BFS starting with beginWord to endWord, count number of steps
		queue<pair<string, int>> toVisit;
		unordered_set<string> visited;

		toVisit.push(make_pair(beginWord, 1));	// not really distance... length of transform seq so need to count beginWord

		while(!toVisit.empty()) {
			int distance = toVisit.front().second;
			string currWord = toVisit.front().first;
			toVisit.pop();

			// check if destination reached
			if(currWord == endWord)
				return distance;

			// if not, add unvisited neighbors to the traversal list
			for(auto neighbor : adjList[currWord]) {
				if(visited.find(neighbor) == visited.end()) {
					visited.insert(neighbor);
					toVisit.push(make_pair(neighbor, distance + 1));
				}
			}
		}

		return 0;	// not found
    }
};
