class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // need a stack for iterative inorder traversal
        std::stack<TreeNode *> treeStack;
        int n = 0;

        while(root || !treeStack.empty()) {
            // keep going left
            while(root) {
                treeStack.push(root);
                root = root->left;
            }

            // reached a null node on the way left
            // go back one node
            root = treeStack.top();
            treeStack.pop();
            n += 1;
            
            // at the kth smallest node
            if(n == k)
                break;

            // go right
            root = root->right;
        }
        return root->val;
    }
};
