/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummyHead;
        dummyHead.next = head;

        ListNode* rightIter = &dummyHead;
        ListNode* leftIter = &dummyHead;
        int sublistLength = 0;

        while(rightIter) {
            if(sublistLength < k) {
                sublistLength += 1;
                rightIter = rightIter->next;
            } else {
                // the sublist is [leftIter, startNode...rightIter, resumeNode]
                // extract the sublist
                ListNode* resumeNode = rightIter->next;
                ListNode* startNode = leftIter->next;
                rightIter->next = NULL;

                // reverse the sublist
                leftIter->next = reverseList(leftIter->next);

                // the reversed sublist is [leftIter, rightIter, startNode, resumeNode]
                // reattach the reversed sublist back
                leftIter->next = rightIter;
                startNode->next = resumeNode;

                // update the iterators and sublist counter
                sublistLength = 0;
                leftIter = startNode;
                rightIter = startNode;
            }
        }

        return dummyHead.next;
    }

    // reverse a list (terminating with null)
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev; 
    }
};
