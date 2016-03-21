// 3. Longest Substring Without Repeating Characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int slow = 0, fast = 0, res = 0;
        bool visited[256] = {false};
        while (fast<n) {
            if (visited[s[fast]]) {
                res = max(res, fast-slow);
                while (s[slow]!=s[fast]) {
                    visited[s[slow]] = false;
                    slow++;
                }
                slow++;
                fast++;
            }
            else {
                visited[s[fast]] = true;
                fast++;
            }
        }
        res = max(res, n-slow);
        return res;
    }
};


class Solution {
public: // hash map
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, res = 0;
        unordered_map<char, int> m;
        while (r<s.size()) {
            if (m.count(s[r])) l = max(l, m[s[r]]+1);
            m[s[r]] = r;
            res = max(res, r-l+1);
            r++;
        }
        return res;
    }
};