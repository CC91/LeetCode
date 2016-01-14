// 297. Serialize and Deserialize Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    int helper(string &data) {
        int pos = data.find(',');
        int val = stoi(data.substr(0, pos));
        data = data.substr(pos+1);
        return val;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "#";
        return to_string(root->val)+','+serialize(root->left)+','+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return dHelper(data);
    }
    
    TreeNode* dHelper(string &data) {
        if (data[0]=='#') {
            if (data.size()>1) data = data.substr(2);
            return NULL;
        } else {
            TreeNode* n = new TreeNode(helper(data));
            n->left = dHelper(data);
            n->right = dHelper(data);
            return n;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));