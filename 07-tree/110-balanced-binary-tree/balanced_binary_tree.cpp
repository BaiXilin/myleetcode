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
    bool isBalanced(TreeNode* root) {
        // edge case: the tree is empty, trivially balanced
        if(!root) return true;

        // if depth of root == -1, tree is unbalanced
        if(findTreeDepth(root) == -1) return false;

        return true;
    }

    // recursively finds the depth of a tree
    // return -1 if the tree is unbalanced at root
    int findTreeDepth(TreeNode* root) {
        // base case: at the bottom of the tree, so depth is 0
        if(!root)
            return 0;

        int leftTreeDepth = findTreeDepth(root->left);
        // if the left subtree is already unbalanced, the entire tree is unbalanced
        if(leftTreeDepth == -1) return -1;

        int rightTreeDepth = findTreeDepth(root->right);
        // if the right subtree is already unbalanced, the entire tree is unbalanced
        if(rightTreeDepth == -1) return -1;

        // both left and right subtree is balanced
        // check if the tree start at root is balanced
        if(abs(leftTreeDepth - rightTreeDepth) > 1) return -1;

        // the tree is balanced, return its depth
        return max(leftTreeDepth, rightTreeDepth) + 1;
    }
};
