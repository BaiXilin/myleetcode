#include <unordered_map>
#include <list>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* copyHeadDummy = new Node(0);
        Node * tail = copyHeadDummy;

        Node *dummyNull = new Node(0);

        // when a node is copied, possible the node random points does not exist yet
        // random node index -> list[copied node address]
        unordered_map<int, list<Node*>> randomMap;
        unordered_map<Node*, int> headMap;
        unordered_map<int, Node*> copiedMap;
        Node* iter = head;
        int index = 0;
        
        while(iter) {
            headMap[iter] = index;
            iter = iter->next; 
            index++;
        }

        index = 0; // index of nodes in the list
        while(head) {
            tail->next = new Node(head->val);
            copiedMap[index] = tail->next;

            // also keep track of the index pointed to by current random
            if(head->random && headMap[head->random] <= index)
                tail->next->random = copiedMap[headMap[head->random]];
            else if(head->random) // save to fill later
                randomMap[headMap[head->random]].push_back(tail->next);
            
            if(randomMap.find(index) != randomMap.end()) {
                for(auto it = randomMap[index].begin(); it != randomMap[index].end(); it++) {
                    (*it)->random = tail->next;
                }
            }

            index++;
            tail = tail->next;
            head = head->next;
        }

        return copyHeadDummy->next;
    }
};

int main() {
    Solution sol;

    //[[7,null],[13,0],[11,4],[10,2],[1,0]]
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);

    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;

    auto copiedHead = sol.copyRandomList(head);
}
