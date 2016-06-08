// 320. Generalized Abbreviation

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res{word};
        helper(word, 0, res);
        return res;
    }
    
    void helper(string word, int start, vector<string> &res) {
        for (int i = start; i < word.size(); i++) {
            for (int j = 1; i + j <= word.size(); j++) {
                string tmp = word.substr(0, i);
                tmp += to_string(j) + word.substr(i + j);
                res.push_back(tmp);
                helper(tmp, i + 1 + to_string(j).size(), res);
            }
        }
    }
};