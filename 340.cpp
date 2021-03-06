// 340. Longest Substring with At Most K Distinct Characters

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int res = 0;
        int left = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
            while (m.size() > k) {
                if (--m[s[left]] == 0) {
                    m.erase(s[left]);
                }
                left++;
            }
            res = max(res, i - left + 1);
        }
        return res;
    }
};



class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int res = 0;
        int left = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]] = i;
            while (m.size() > k) {
                if (m[s[left]] == left) {
                    m.erase(s[left]);
                }
                left++;
            }
            res = max(res, i - left + 1);
        }
        return res;
    }
};