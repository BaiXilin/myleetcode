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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // two pointers, distance n apart
        // when right ptr reaches end of list, remove the node after left ptr
        
        // create a dummy head node makes removing head easier
        ListNode dummy = ListNode();
        dummy.next = head;

        ListNode *left = &dummy;
        ListNode *right = &dummy;

        while(right && n > 0) {
            right = right->next;
            n--;
        }

        // start iterating
        while(right && right->next) {
            left = left->next;
            right = right->next;
        } 

        left->next = left->next->next;

        return dummy.next;
    }
};

int main() {
    Solution sol;

    //ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    //sol.removeNthFromEnd(head, 2);

    ListNode *head = new ListNode(1, new ListNode(2));
    head = sol.removeNthFromEnd(head, 1);

    while(head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}
