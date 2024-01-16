#include <unordered_map>

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
        Node *copyDummyHead = new Node(0);
        Node *tail = copyDummyHead;
        
        // keep track of a mapping between origin node address -> copied node address
        unordered_map<Node*, Node*> nodeMap;
        
        // deep copy all the node values
        // leave random field empty, but construct node mapping
        Node *iter = head;
        while(iter) {
            tail->next = new Node(iter->val);
            nodeMap[iter] = tail->next;
            tail = tail->next;
            iter = iter->next;
        }

        // another iteration to reconstruct node mapping
        tail = copyDummyHead->next;
        iter = head;
        while(tail) {
            if(iter->random == NULL)
                tail->random = NULL;
            else
                tail->random = nodeMap[iter->random];
            tail = tail->next;
            iter = iter->next;
        }

        return copyDummyHead->next;
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
