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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* iter1 = list1, *iter2 = list2;
        ListNode* mergedHead = new ListNode();
        ListNode* mergedIter = mergedHead;
        while(iter1 && iter2) {
            // select the smaller of two heads
            if(iter1->val < iter2->val) {
                mergedIter->next = iter1;
                iter1 = iter1->next;
            } else {
                mergedIter->next = iter2;
                iter2 = iter2->next;
            }
            mergedIter = mergedIter->next;
        }

        // one of the list is empty
        ListNode *nonEmptyList = (iter1) ? iter1 : iter2;
        while(nonEmptyList) {
            mergedIter->next = nonEmptyList;
            mergedIter = mergedIter->next;
            nonEmptyList = nonEmptyList->next;

        }
        
        return mergedHead->next;
    }
};

int main() {
    Solution sol;

    ListNode* list1 = new ListNode(1);
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(2);

    auto mergedHead = sol.mergeTwoLists(list1, list2);

    while(mergedHead) {
        std::cout << mergedHead->val << " ";
        mergedHead = mergedHead->next;
    }
    std::cout << std::endl;
}
