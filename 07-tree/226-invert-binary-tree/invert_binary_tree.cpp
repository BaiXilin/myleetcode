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
    TreeNode* invertTree(TreeNode* root) {
        // base case: the root is a leaf node
        if(root->left == NULL && root->right == NULL)
            return root;

        TreeNode* invertedLeft = NULL;
        TreeNode* invertedRight = NULL;

        if(root->left != NULL)
            invertedLeft = invertTree(root->left);
        if(root->right != NULL)
            invertedRight = invertTree(root->right);

        // invert the children of the current root
        root->left = invertedRight;
        root->right = invertedLeft;

        return root;
    }
};
