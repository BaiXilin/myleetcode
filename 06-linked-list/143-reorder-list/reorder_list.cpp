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
    void reorderList(ListNode* head) {
        // split the linked list in two halves
        // reverse the second half
        // then merge the first & second half
        // eg. 1->2->3->4->5
        // 1st half: 1->2->3
        // 2nd half: 4->5 --> reversed: 5->4
        // merged: 1->5->2->4->3 is what we want
        
        // to split in half, need to know length of linked list
        ListNode* iter = head;
        int length = 0;
        while(iter) {
            length++;
            iter = iter->next;
        }

        // no reordering done
        if(length == 0 || length == 1 || length == 2)
            return;

        // find the spliting point
        iter = head;
        length = length / 2;
        while(iter && length >= 0) {
            iter = iter->next;
            length--;
        }

        // reverse the 2nd half of list
        ListNode *halfnode = reverselist(iter);
        iter = head;

        while(iter->next->next)
            iter = iter->next;
        iter->next = nullptr;

        ListNode *iter2 = halfnode;
        iter = head;

        while(iter) {
            if(!iter2) {
                iter = iter->next;
            } else {
                ListNode *iternext = iter->next;
                ListNode *iter2next = iter2->next;
                iter->next = iter2;
                iter->next->next = iternext;
                iter = iternext;
                iter2 = iter2next;
            }
        }
        
        return;
    }

    ListNode* reverselist(ListNode *head) {
        ListNode *curr = head;
        ListNode *prev = nullptr;

        while(curr) {
            ListNode *tempnext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tempnext;
        }

        return prev;
    }
};

int main() {
    Solution sol;
 
    // 1 -> 2 -> 3 -> 4, output is 1 -> 4 -> 2 -> 3
    //ListNode head = ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    
    // empty list
    //ListNode head = nullptr;

    // single element list
    //ListNode head = ListNode(1);

    // odd length
    ListNode head = ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    //ListNode head = ListNode(1, new ListNode(2));

    sol.reorderList(&head);

    ListNode *iter = &head;
    while(iter) {
        std::cout << iter->val << " ";
        iter = iter->next;
    }
    std::cout << std::endl;
}
