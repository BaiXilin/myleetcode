#include <iostream>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // base case: head is empty
        if(!head)
            return nullptr;

        // base case: at end of list
        if(!head->next)
            return head;
        
        // recursive case: shrink size of list by one
        auto newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};

int main() {
    auto head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next =  new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    head = sol.reverseList(head);

    while(head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}
