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
    vector<int> rightSideView(TreeNode* root) {
        // General Idea: Use level order traversal
        // return the last element on each level

        vector<int> right_side_view;

        vector<vector<int>> level_order = levelOrderTraversal(root);

        for(auto i : level_order) {
            right_side_view.push_back(i.back());
        }

        return right_side_view;
    }

    vector<vector<int>> levelOrderTraversal(TreeNode * root) {
        vector<vector<int>> level_order_val;
        vector<vector<TreeNode*>> level_order_node;

        if(!root)
            return level_order_val;

        // push in the root level
        level_order_node.push_back(vector<TreeNode*>{root});
        level_order_val.push_back(vector<int>{root->val});

        // iteratively traversal every level
        while(true) {
            vector<TreeNode*> curr_level_node;
            vector<int> curr_level_val;
            bool next_level_empty = true;

            for(auto node : level_order_node.back()) {
                if(node->left) {
                    curr_level_node.push_back(node->left);
                    curr_level_val.push_back(node->left->val);
                    next_level_empty = false;
                }
                if(node->right) {
                    curr_level_node.push_back(node->right);
                    curr_level_val.push_back(node->right->val);
                    next_level_empty = false;
                }
            }

            if(next_level_empty)
                break;

            level_order_node.push_back(curr_level_node);
            level_order_val.push_back(curr_level_val);
        }

        return level_order_val;
    }
};
