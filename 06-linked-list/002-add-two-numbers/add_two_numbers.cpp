#include <iostream>
#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // add the numbers digit by digit
        // need a carry bit
        bool carry = false;
        ListNode *dummy = new ListNode();
        ListNode *tail = dummy;

        while(l1 || l2) {
            // add two numbers
            int result = 0;

            if(l1) {
                result += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                result += l2->val;
                l2 = l2->next;
            }
            
            if(carry)
                result++;
            if(result >= 10)
                carry = true;
            else
                carry = false;
            result %= 10;
            
            tail->next = new ListNode(result);
            tail = tail->next;
        }

        if(carry)
            tail->next = new ListNode(1);
        return dummy->next;
    }
};

int main() {
    Solution sol;

    ListNode *l1 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
    ListNode *l2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));

    ListNode *rl = sol.addTwoNumbers(l1, l2);
    while(rl) {
        std::cout << rl->val << " ";
        rl = rl->next;
    }
    std::cout << std::endl;
}
