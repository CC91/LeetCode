// 411. Minimum Unique Word Abbreviation

class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        if (dictionary.empty()) return to_string((int)target.size());
        priority_queue<pair<int, string>, vector<pair<int, string>>, 
        	greater<pair<int, string>>> q;
        q = helper(target);
        while (!q.empty()) {
            auto t = q.top(); q.pop();
            bool conflict = false;
            for (string word : dictionary) {
                if (isValid(word, t.second)) {
                    conflict = true;
                    break;
                }
            }
            if (!conflict) return t.second;
        }
        return "";
    }
    
    priority_queue<pair<int, string>, vector<pair<int, string>>, 
        greater<pair<int, string>>> helper(string target) {
        priority_queue<pair<int, string>, vector<pair<int, string>>, 
            greater<pair<int, string>>> res;
        for (int i = 0; i < pow(2, target.size()); i++) {
            string tmp = "";
            int cnt = 0;
            int len = 0;
            for (int j = 0; j < target.size(); j++) {
                if ((i >> j) & 1) {
                    cnt++;
                } else {
                    if (cnt != 0) {
                        tmp += to_string(cnt);
                        cnt = 0;
                        len++;
                    }
                    tmp += target[j];
                    len++;
                }
            }
            if (cnt > 0) {
                tmp += to_string(cnt);
                len++;
            }
            res.push({len, tmp});
        }
        return res;
    }
    
    bool isValid(string word, string abbr) {
        int i = 0;
        int j = 0;
        while (i < word.size() && j < abbr.size()) {
            if (isdigit(abbr[j])) {
                int len = 0;
                while (j < abbr.size() && isdigit(abbr[j])) {
                    len = len * 10 + (abbr[j++] - '0');
                }
                i += len;
            } else if (word[i++] != abbr[j++]) {
                return false;
            }
        }
        return i == word.size() && j == abbr.size();
    }
};