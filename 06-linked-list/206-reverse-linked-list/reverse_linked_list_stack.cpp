#include <iostream>
#include <stack>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ~ListNode() {
        if(this->next) {
            auto nextNode = this->next;
            this->next = nullptr;
            delete(nextNode);
        }
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // first traverse the linked list and push nodes into a stack
        std::stack<ListNode*> nodes;
        ListNode* iter = head;
        while(iter) {
            nodes.push(iter);
            iter = iter->next;
        }

        // pop nodes from stack and rearrange
        if(!nodes.empty()) {
            head = nodes.top();
            head->next = nullptr;
            nodes.pop();
        } else {
            return head;
        }
        iter = head;
        while(!nodes.empty()) {
            iter->next = nodes.top();
            iter = iter->next;
            nodes.pop();
        }
        iter->next = nullptr;
        return head;
    }
};

int main() {
    Solution sol;

    /*ListNode *head = new ListNode(1);

    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    */
    ListNode *head = nullptr;
    head = sol.reverseList(head);
    
    ListNode* iter = head;
    while(iter) {
        std::cout << iter->val << " ";
        iter = iter->next;
    }
    std::cout << std::endl;

    delete(head);
}
