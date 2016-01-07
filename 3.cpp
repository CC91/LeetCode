// 3. Longest Substring Without Repeating Characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int slow = 0, fast = 0, Max = 0;
        bool visited[256] = {false};
        while(fast<n) {
            if (visited[s[fast]]) {
                Max = max(Max, fast-slow);
                while (s[slow] != s[fast]) {
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
        Max = max(Max, n-slow);
        return Max;
    }
};

