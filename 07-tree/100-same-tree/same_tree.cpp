/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // base case: both are empty tree
        if(!p && !q) return true;

        // edge case: avoid dealing with empty tree
        if(!p && q) return false;
        if(p && !q) return false;

        // compare the value at current node
        if(p->val != q->val) return false;

        // compare the left subtree of each tree
        if(!isSameTree(p->left, q->left)) return false;

        // compare the right subtree of each tree
        if(!isSameTree(p->right, q->right)) return false;

        return true;
    }
};
