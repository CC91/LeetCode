// 187. Repeated DNA Sequences

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> m;
        vector<string> res;
        for (int i=0, t=0; i<s.size(); i++) {
            if (m[t=t<<3 & 0x3FFFFFFF | s[i]&7]++ ==1) res.push_back(s.substr(i-9, 10)); // 0x3FFFFFFF represents 30bits 
        }
        return res;
    }
};