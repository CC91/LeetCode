// 76. Minimum Window Substring

class Solution {
public: // 2 pointers with hash table
    string minWindow(string s, string t) {
        if (s.empty() ||t.empty()) return "";
        unordered_map<char, int> m;
        for (char c:t) m[c]++;
        int i = 0, j = 0, pos = -1, cnt = 0, len = s.size()+1; // i is the left boundary, j is the right boundary
        while (j<s.size()) {
            if (m.count(s[j])) {
                if (m[s[j]]-->0) cnt++;
            }
            while (cnt==t.size()) {
                if (len>j-i+1) {
                    len = j-i+1;
                    pos = i; 
                }
                char c = s[i++];
                if (m.count(c)) {
                    m[c]++;
                    if (m[c]>0) cnt--;
                }
                
            }
            j++;
        }
        return pos==-1?"":s.substr(pos, len);
    }
};