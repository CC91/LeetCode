// 76. Minimum Window Substring 

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        int start = 0;
        int end = 0;
        int pos = -1;
        int len = s.size() + 1;
        int cnt = 0;
        unordered_map<char, int> m;
        for (char c : t) m[c]++;
        while (end < s.size()) {
            if (m[s[end++]]-- > 0) cnt++;
            while (cnt == t.size()) {
                if (len > end - start) {
                    len = end -start;
                    pos = start;
                }
                if (m[s[start++]]++ == 0) cnt--;
            }
        }
        return pos == -1? "" : s.substr(pos, len);
    }
};