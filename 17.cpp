// 17. Letter Combinations of a Phone Number 

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        string letters[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string comb(digits.size(), '\0');
        helper(digits, letters, comb, 0, res);
        return res;
    }
    
    void helper(string digits, string letters[], string &comb, int i, vector<string> &res) {
        if (i == digits.size()) {
            res.push_back(comb);
            return;
        }
        string cur = letters[digits[i]-'0'];
        for (int j = 0; j < cur.size(); j++) {
            comb[i] = cur[j];
            helper(digits, letters, comb, i+1, res);
        }
    }
};