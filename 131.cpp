// 131. Palindrome Partitioning

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string> tmp;
        vector<vector<string>> res;
        vector<vector<bool>> isP(n, vector<bool>(n, false));
        for (int i=n-1; i>=0; i--) {
            for (int j=i; j<n; j++) {
                if ((i+1>=j-1 ||isP[i+1][j-1]) && s[i]==s[j]) isP[i][j]=true;
            }
        }
        findP(s, 0, isP, tmp, res);
        return res;
    }
    
    void findP(string s, int start, vector<vector<bool>> &isP, vector<string> &tmp, vector<vector<string>> &res) {
        if (start==s.size()) {
            res.push_back(tmp);
            return;
        }
        for (int i=start; i<s.size(); i++) {
            if (isP[start][i]) {
                tmp.push_back(s.substr(start, i-start+1));
                findP(s, i+1, isP, tmp, res);
                tmp.pop_back();
            }
        }
    }
};