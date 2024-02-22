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

    int maxPathSum(TreeNode* root) {
        int global_max_sum = INT_MIN;
        int recur_max_sum = maxPathSum_recur(root, &global_max_sum);

        return (global_max_sum > recur_max_sum) ? global_max_sum : recur_max_sum;
    }

    int maxPathSum_recur(TreeNode* root, int* global_max_sum) {
        // null node so no path possible
        if(!root)
            return 0;

        // max path sum for the left subtree
        int left_path_sum = maxPathSum_recur(root->left, global_max_sum);
        // max path sum for the right subtree
        int right_path_sum = maxPathSum_recur(root->right, global_max_sum);

        // sum the left and right subtree together
        int local_path_sum = left_path_sum + right_path_sum + root->val;
        // this may outweight the global max sum
        if(local_path_sum > *global_max_sum)
            *global_max_sum = local_path_sum;

        // in case the left/right subtree outweight the global max sum
        if(left_path_sum > *global_max_sum && root->left)
            *global_max_sum = left_path_sum;
        if(right_path_sum > *global_max_sum && root->right)
            *global_max_sum = right_path_sum;
        // maybe the current node outweight the global max sum
        if(root->val > *global_max_sum)
            *global_max_sum = root->val;

        if(root->val > (left_path_sum + root->val) && root->val > (right_path_sum + root->val))
            return root->val;
        else
            return (left_path_sum > right_path_sum) ? (left_path_sum + root->val) : (right_path_sum + root->val);
    }
};
