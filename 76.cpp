// 76. Minimum Window Substring

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() ||s.size()<t.size()) return "";
        unordered_map<char, int> m;
        for (char c:t) {
            if (m.count(c)) m[c]++;
            else m[c]=1;
        }
        
        int left =0,  right = 0;
        int len = s.size()+1;
        int cnt = 0;
        int minLeft = -1;
        
        while (right<s.size()) {
            char curC = s[right];
            if (m.count(curC)) {
                if (m[curC]-->0) cnt++;
            }
            //m[curC]--;
            while (cnt==t.size()) {
                if (len>right-left+1) {
                    len = right-left+1;
                    minLeft = left;
                }
                char leftC = s[left++];
                if (m.count(leftC)) {
                    m[leftC]++;
                    if (m[leftC]>0) cnt--;
                }
            }
            right++;
        }
        return minLeft==-1?"":s.substr(minLeft, len);
    }
};