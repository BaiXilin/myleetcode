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
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, nullptr, nullptr);
    }

    bool isValidBSTHelper(TreeNode* root, TreeNode* min, TreeNode* max) {
        // base case: an empty BST is valid
        if(!root)
            return true;

        if(min && root->val <= min->val)
            return false;

        if(max && root->val >= max->val)
            return false;

        return isValidBSTHelper(root->left, min, root) && isValidBSTHelper(root->right, root, max);
    }
};
