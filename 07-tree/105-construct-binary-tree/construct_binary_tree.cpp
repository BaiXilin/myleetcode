#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // by the pre-order traversal rule, preorder[0] is the root of the tree
        TreeNode* root = buildSubtree(preorder, inorder, 0, 0, inorder.size());
        return root;
    }

    TreeNode* buildSubtree(vector<int>& preorder, vector<int>& inorder, unsigned preorder_start, unsigned inorder_start, unsigned inorder_end) {
        // base case: when the subtree has no node, subtree is null
        if(inorder_end - inorder_start == 0)
            return NULL;

        // base case: when the subtree has only one node, the subtree contains that one node only
        if(inorder_end - inorder_start == 1) 
            return new TreeNode(inorder[inorder_start]);

        // subtree has at least 2 nodes, find the root of the subtree
        // by pre-order traversal rule (root, left, right), the first node in pre-order that exists in subtree vector is the root
        unsigned int i = 0;
        for(i = inorder_start; i < inorder_end; i++)
            if(inorder[i] == preorder[preorder_start])
                break;

        // found the root of the subtree, create a node for it
        TreeNode* subtree_root = new TreeNode(inorder[i]);

        // separate the subtree vector into left and right, and attach the sub-subtrees to subtree root
        unsigned left_inorder_start= inorder_start;
        unsigned left_inorder_end = i;

        unsigned right_inorder_start = i + 1;
        unsigned right_inorder_end = inorder_end;

        // using the size of left and right subtree, the preorder vector can also be separated into left and right subtree
        // and the first element of each subtree is the root of that subtree
        unsigned left_preorder_start = preorder_start + 1;
        unsigned right_preorder_start = preorder_start + (left_inorder_end - left_inorder_start) + 1;

        // construct the subtrees and attach to the subtree root
        subtree_root->left = buildSubtree(preorder, inorder, left_preorder_start, left_inorder_start, left_inorder_end);
        subtree_root->right = buildSubtree(preorder, inorder, right_preorder_start, right_inorder_start, right_inorder_end);

        return subtree_root;
    }
};

int main() {
    Solution sol;
    
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode* root = sol.buildTree(preorder, inorder);
}

