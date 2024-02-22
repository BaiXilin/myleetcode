/**
 * Definition for a binary tree node.
 **/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int globalMaxDiameter = 0;

        int nonGlobalMaxDiameter = diameterOfBinaryTreeHelper(root, &globalMaxDiameter);
        return max(nonGlobalMaxDiameter, globalMaxDiameter);
    }

    int diameterOfBinaryTreeHelper(TreeNode* root, int* globalMaxDiameter) {
        // base case: the current node is a leaf
        if(root->left == NULL && root->right == NULL)
            return 0;

        // recurse on both children if they exist
        int leftDia = 0, rightDia = 0;
        if(root->left) {
            leftDia = diameterOfBinaryTreeHelper(root->left, globalMaxDiameter);
            leftDia += 1;
        }

        if(root->right) {
            rightDia = diameterOfBinaryTreeHelper(root->right, globalMaxDiameter);
            rightDia += 1;
        }

        if(leftDia + rightDia > *globalMaxDiameter)
            *globalMaxDiameter = leftDia + rightDia;

        return max(leftDia, rightDia);
    }
};

int main() {
    Solution sol;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int diameter = sol.diameterOfBinaryTree(root);
    cout << "diameter = " << diameter << endl;
}
