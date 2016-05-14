// 93. Restore IP Addresses

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        helper(s, "", res, 4);
        return res;
    }
    
    bool isValid(string s) {
        if (s.empty() || s.size() > 3) return false;
        if (s[0] == '0' && s.size() != 1) return false;
        if (s.size() == 3 && stoi(s) > 255) return false;
        return true;
    }
    
    void helper(string s, string r, vector<string> &res, int i) {
        if (i == 0) {
            if (s.empty()) {
                res.push_back(r);
            }
            return;
        }
        for (int j = 1; j < 4; j++) {
            if (s.size() >= j && isValid(s.substr(0, j))) {
                if (i == 1) helper(s.substr(j), r + s.substr(0, j), res, i - 1);
                else helper(s.substr(j), r + s.substr(0, j) + '.', res, i - 1);
            }
        }
    }
};