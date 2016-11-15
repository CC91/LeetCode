// 438. Find All Anagrams in a String

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int m[128] = {0};
        int cnt = p.size();
        int i = 0;
        int start = 0;
        for (auto a : p) {
            m[a]++;
        }
        while (i < s.size()) {
            if (m[s[i++]]-- > 0) {
                cnt--;
            }
            if (cnt == 0) {
                res.push_back(start);
            }
            if (i - start == p.size() && m[s[start++]]++ >= 0) {
                cnt++;
            }
        }
        return res;
    }
};