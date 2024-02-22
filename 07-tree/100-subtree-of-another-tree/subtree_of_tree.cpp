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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // base case: if both trees are empty, they are the same
        if(!root && !subRoot) return true;

        // edge case: avoid dealing with empty tree
        // subRoot not at bottom but root is empty. Not subtree
        if(!root || !subRoot) return false;

        // possibly subRoot is the root of a same subtree
        if(root->val == subRoot->val && isSameTree(root, subRoot))
            return true;

        if(isSubtree(root->left, subRoot)) return true;
        if(isSubtree(root->right, subRoot)) return true;

        return false;
    }

    bool isSameTree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;

        if(!root || !subRoot) return false;

        if(root->val != subRoot->val) return false;

        return (isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right));
    }
};
