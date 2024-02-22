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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> tree_inorder;

        inOrderTraversal(root, &tree_inorder);

        return tree_inorder[k - 1];
    }

    // recursively inorder traverse the tree
    void inOrderTraversal(TreeNode* root, vector<int>* tree_inorder) {
        // base case: if the tree is empty
        if(!root)
            return;

        // traverse the left subtree first
        inOrderTraversal(root->left, tree_inorder);

        // add the current node
        tree_inorder.push_back(root->val);

        // traverse the right subtree last
        inOrderTraversal(root->right, tree_inorder);

        return;
    }
};
