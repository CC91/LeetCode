// 30. Substring with Concatenation of All Words

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty() ||s.empty()) return res;
        int n = words.size(), l = words[0].size();
        unordered_map<string, int> w;
        for (string s:words) w[s]++;
        int i = 0;
        while (i+n*l-1<s.size()) {
            unordered_map<string, int> m;
            int j = 0;
            while (j<n) {
                string str = s.substr(i+j*l, l);
                if (!w.count(str)) break;
                m[str]++;
                if (m[str]>w[str]) break;
                j++;
            }
            if (j==n) res.push_back(i);
            i++;
        }
        return res;
    }
};