// 49. Group Anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if (strs.empty()) return res;
        unordered_map<string, multiset<string>> m;
        for (string s:strs) {
            string t = s;
            sort(t.begin(), t.end());
            m[t].insert(s);
        }
        for (auto a:m) {
            vector<string> anagram(a.second.begin(), a.second.end());
            res.push_back(anagram);
        }
        return res;
    }
};