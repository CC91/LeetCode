// 159. Longest Substring with At Most Two Distinct Characters

class Solution {
public: // hash map
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int res = 0;
        int left = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
            while (m.size() > 2) {
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
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int res = 0;
        int left = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]] = i;
            while (m.size() > 2) {
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