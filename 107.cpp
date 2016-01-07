//107. Binary Tree Level Order Traversal II

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public: // BFS
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return vector<vector<int>> ();
        vector<pair<TreeNode*, int>> p;
        int cnt = 0, lev = 1;
        p.push_back(make_pair(root, 1));
        while (cnt<p.size()) {
            TreeNode* n = p[cnt].first;
            lev = p[cnt].second;
            if (n->left) p.push_back(make_pair(n->left, lev+1));
            if (n->right) p.push_back(make_pair(n->right, lev+1));
            cnt++;
        }
        vector<vector<int>> res(lev, vector<int> ());
        for (int i=0; i<p.size(); i++) res[lev-p[i].second].push_back(p[i].first->val);
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> curL;
        queue<TreeNode*> nextL;
        vector<int> tmp;
        curL.push(root);
        while (!curL.empty()) {
            TreeNode* n = curL.front();
            curL.pop();
            if (n) {
                tmp.push_back(n->val);
                nextL.push(n->left);
                nextL.push(n->right);
            }
            if (curL.empty()) {
                if (!tmp.empty()) res.push_back(tmp);
                tmp.clear();
                swap(curL, nextL);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};