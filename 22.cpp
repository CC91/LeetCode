// 22. Generate Parentheses 

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n <=0 ) return res;
        string tmp = "";
        helper(tmp, res, n, n);
        return res;
    }
    
    void helper(string tmp, vector<string> &res, int left, int right) {
        if (left > right) return;
        if (left == 0 && right == 0) {
            res.push_back(tmp);
            return;
        }
        if (left > 0) helper(tmp+'(', res, left-1, right);
        if (right > 0) helper(tmp+')', res, left, right-1);
    }
};