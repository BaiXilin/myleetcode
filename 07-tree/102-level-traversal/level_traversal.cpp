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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelOrderVal;
        vector<vector<TreeNode *>> levelOrderNode;

        // empty tree. trivially return empty result
        if(!root)
            return levelOrderVal;

        // add root level
        levelOrderVal.push_back(vector<int>{root->val});
        levelOrderNode.push_back(vector<TreeNode *>{root});

        bool nextLevelEmpty = false;
        while(!nextLevelEmpty) {
            vector<int> nextLevelVal;
            vector<TreeNode *> nextLevelNode;
            nextLevelEmpty = true;
            for(auto i : levelOrderNode.back()) {
                if(i->left) {
                    nextLevelEmpty = false;
                    nextLevelVal.push_back(i->left->val);
                    nextLevelNode.push_back(i->left);
                }
                if(i->right) {
                    nextLevelEmpty = false;
                    nextLevelVal.push_back(i->right->val);
                    nextLevelNode.push_back(i->right);
                }
            }

            if(nextLevelEmpty)
                break;

            levelOrderVal.push_back(nextLevelVal);
            levelOrderNode.push_back(nextLevelNode);
        }

        return levelOrderVal;
    }
};
