#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

};
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // the idea is same as merging two sorted lists
        // but merge two lists at a time
        int k = lists.size();

        if(k == 0)
            return nullptr;
        else if(k == 1)
            return lists[0];

        for(int i = 1; i < k; i++) {
            lists[0] = mergeTwoLists(lists[0], lists[i]);
        }
        return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // make sure that actual merge is only performed when non-empty lists
        if(!l1 && !l2)
            return nullptr;
        else if(!l1)
            return l2;
        else if(!l2)
            return l1;

        ListNode* head = nullptr;
        if(l1->val < l2->val) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }
        
        ListNode *curr = head; // iterator
        while(l1 && l2) {
            if(l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        // at least one list is empty
        if(l1)
            curr->next = l1;
        else
            curr->next = l2;

        return head;
    }
};

int main() {
    Solution sol;

    ListNode *l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode *l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode *l3 = new ListNode(2, new ListNode(6));
    vector<ListNode*> lists = {l1, l2, l3};

    ListNode* mergedList = sol.mergeKLists(lists);
    while(mergedList) {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    cout << endl;
}
