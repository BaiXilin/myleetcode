/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;

        // search for p and q in root's descendants
        TreeNode* leftRes = lowestCommonAncestor(root->left, p, q); 
        TreeNode* rightRes = lowestCommonAncestor(root->right, p, q);

        if((root == p || root == q) && (!leftRes || !rightRes))
            return root;
        
        if(leftRes && rightRes)
            return root;
        
        if(leftRes)
            return leftRes;
        if(rightRes)
            return rightRes;
        
        return NULL;
    }
};
