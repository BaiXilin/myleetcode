#include <iostream>
#include <string>
#include <sstream>
#include <vector>

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
        string serializedStr = "";
        // if empty binary tree, return empty string
        if(!root)
            return serializedStr;

        // serialize the binary tree using a level-order traversal
        // node values separated by comma, empty node's value is char 'n'
        vector<vector<TreeNode *>> levelOrderNodes;
        level_order_traversal(root, levelOrderNodes);

        // concat the vector into a string
        for(auto levelNode : levelOrderNodes) {
            for(auto node: levelNode) {
                if(node) {
                    serializedStr += to_string(node->val);
                    serializedStr += ',';
                } else
                    serializedStr += "n,";
            }
        }

        // get rid of the trailing comma
        serializedStr.pop_back();

        return serializedStr;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // if empty string, return an empty binary tree
        if(data.length() == 0)
            return NULL;

        stringstream ss(data);
        string token;
        vector<TreeNode *> nodes;

        while(getline(ss, token, ',')) {
            if(token == "n")
                nodes.push_back(NULL);
            else
                nodes.push_back(new TreeNode(stoi(token)));
        }

        for(int i = 0; i < nodes.size() / 2; i++) {
            if(!nodes[i]) {
                nodes[i]->left = nodes[2 * i + 1];
                nodes[i]->right = nodes[2 * i + 2];
            }
        }
        
        return nodes[0];
    }

    void level_order_traversal(TreeNode* root, vector<vector<TreeNode *>> &levelOrderNodes) {
        // empty binary tree
        if(!root)
            return;

        // insert the root node
        levelOrderNodes.push_back(vector<TreeNode *>{root});
 
        // iteratively traverse each level
        while(true) {
            bool nextLevelEmpty = true;
            // vector for this level's nodes
            vector<TreeNode *> nodes;

            for(auto prev_level_node : levelOrderNodes.back()) {
                if(!prev_level_node) {
                    nodes.push_back(NULL);
                    nodes.push_back(NULL);
                    continue;
                }
                
                if(prev_level_node->left || prev_level_node->right)
                    nextLevelEmpty = false;

                nodes.push_back(prev_level_node->left);
                nodes.push_back(prev_level_node->right);
            }

            if(nextLevelEmpty)
                break;
            else
                levelOrderNodes.push_back(nodes);
        }
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
    TreeNode *deserializedTree = deser.deserialize(serializedStr);
}
