// 140. Word Break II 

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        string tmp;
        vector<string> res;
        int len = s.size();
        vector<bool> isValid(len+1, true);
        helper(0, s, wordDict, len, tmp, res, isValid);
        return res;;
    }
    
    void helper(int start, string s, unordered_set<string>& wordDict, int len, string tmp, vector<string> &res, vector<bool> &isValid) {
        if (start==len) {
            res.push_back(tmp.substr(0, tmp.size()-1));
            return;
        }
        for (int i=start; i<len; i++) {
            string cur = s.substr(start, i-start+1);
            if (wordDict.count(cur) && isValid[i+1]) {
                tmp.append(cur).append(" ");
                int beforeSize = res.size();
                helper(i+1, s, wordDict, len, tmp, res, isValid);
                if (res.size()==beforeSize) isValid[i+1] = false;
                tmp.resize(tmp.size()-cur.size()-1);
            }
        }
    }
};

