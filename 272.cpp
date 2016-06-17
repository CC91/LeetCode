// 272. Closest Binary Search Tree Value II

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
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        stack<TreeNode*> smaller;
        stack<TreeNode*> larger;
        while (root) {
            if (target >= root -> val) {
                smaller.push(root);
                root = root -> right;
            } else {
                larger.push(root);
                root = root -> left;
            }
        }
        while (k-- > 0) {
            if (larger.empty() || !smaller.empty() && 
            	target - smaller.top() -> val 
            	<= larger.top() -> val - target) {
                res.push_back(smaller.top() -> val);
                getSmaller(smaller);
            } else {
                res.push_back(larger.top() -> val);
                getLarger(larger);
            }
        }
        return res;
    }
    
    void getSmaller(stack<TreeNode*> &smaller) {
        TreeNode* t = smaller.top();
        smaller.pop();
        if (t -> left) {
            smaller.push(t -> left);
            while (smaller.top() -> right) {
                smaller.push(smaller.top() -> right);
            }
        }
    }
    
    void getLarger(stack<TreeNode*> &larger) {
        TreeNode *t = larger.top();
        larger.pop();
        if (t -> right) {
            larger.push(t -> right);
            while (larger.top() -> left) {
                larger.push(larger.top() -> left);
            }
        }
    }
};



class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        helper(root, target, k, res);
        return res;
    }
    
    void helper(TreeNode* root, double target, int k, vector<int> &res) {
        if (!root) {
            return;
        }
        helper(root -> left, target, k, res);
        if (res.size() < k) {
            res.push_back(root -> val);
        } else if (abs(root -> val - target) < abs(res[0] - target)) {
            res.erase(res.begin());
            res.push_back(root -> val);
        }
        helper(root -> right, target, k, res);
    }
};



class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *t = root;
        while (t || !s.empty()) {
            while (t) {
                s.push(t);
                t = t -> left;
            }
            t = s.top();
            s.pop();
            if (res.size() < k) {
                res.push_back(t -> val);
            } else if (abs(t -> val - target) < abs(res[0] - target)) {
                res.erase(res.begin());
                res.push_back(t -> val);
            }
            t = t -> right;
        }
        return res;
    }
};