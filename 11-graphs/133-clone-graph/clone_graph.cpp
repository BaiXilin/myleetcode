#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
		// rule out empty node case
		if(!node)
			return nullptr;

		// use a map to store address of cloned nodes
		unordered_map<int, Node*> clonedNodes;
		
		// first clone the given "root" node
		Node* root = new Node(node->val);
		// cloned nodes added to the map to avoid duplicate creation
		clonedNodes[root->val] = root;
		
		// perform iterative BFS traversal
		queue<Node *> nodeQueue;
		unordered_set<int> visitedNodes;
		nodeQueue.push(node);	// Note: queue should hold nodes from the 
								// original graph as neighbors are there

		while(!nodeQueue.empty()) {
			// get the current node
			Node* currNode = nodeQueue.front(); // original node
			nodeQueue.pop();
			visitedNodes.insert(currNode->val);

			// traverse the current node's neighbors
			for(auto& neighbor : currNode->neighbors) {
				// create the neighbor node if it does not exist
				int neighborVal = neighbor->val;
				
				// has this node benn cloned?
				if(clonedNodes.find(neighborVal) == clonedNodes.end())
					clonedNodes[neighborVal] = new Node(neighborVal);

				// add the cloned node to currNode's adj list
				Node* currClonedNode = clonedNodes[currNode->val];
				currClonedNode->neighbors.push_back(clonedNodes[neighborVal]);

				// add the neighbor node to to-visit queue if never visited
				if(visitedNodes.find(neighborVal) == visitedNodes.end())
					nodeQueue.push(neighbor);
			}
		}

		// return the cloned root node
		return root;
    }
};

int main() {
	Node* n1 = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);

	n1->neighbors.push_back(n2);
	n1->neighbors.push_back(n4);
	n3->neighbors.push_back(n2);
	n3->neighbors.push_back(n4);

	n2->neighbors.push_back(n1);
	n2->neighbors.push_back(n3);
	n4->neighbors.push_back(n1);
	n4->neighbors.push_back(n3);

	Solution sol;
	auto clonedGraph = sol.cloneGraph(n1);
}
