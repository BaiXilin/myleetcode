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
    int goodNodes(TreeNode* root) {
        int goodNodesCount = 0;

        if(!root)
            return 0;

        goodNodesHelper(root, &goodNodesCount, root->val);

        return goodNodesCount;
    }

    void goodNodesHelper(TreeNode* root, int* goodNodesCount, int maxValOnPath) {
        if(!root)
            return;

        if(root->val >= maxValOnPath) {
            *goodNodesCount += 1;
            maxValOnPath = root->val;
        }

        goodNodesHelper(root->left, goodNodesCount, maxValOnPath);
        goodNodesHelper(root->right, goodNodesCount, maxValOnPath);
    }
};
