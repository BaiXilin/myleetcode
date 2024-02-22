#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream oss;

        inorderTraversal(root, oss);

        return oss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        
        return deserialize_recur(iss);
    }
    
    void inorderTraversal(TreeNode *root, ostringstream &oss) {
        if(root) {
            oss << root->val << " ";
            inorderTraversal(root->left, oss);
            inorderTraversal(root->right, oss);
        } else {
            oss << "# ";
        }
    }

    TreeNode* deserialize_recur(istringstream &iss) {
        string str;
        iss >> str;
        if(str == "#")
            return NULL;

        TreeNode *root = new TreeNode(stoi(str));
        root->left = deserialize_recur(iss);
        root->right = deserialize_recur(iss);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
int main() {
    Codec ser, deser;
    
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(5);

    string serializedStr = ser.serialize(root);
    cout << serializedStr << endl;

    TreeNode * deser_root = deser.deserialize(serializedStr);
}
