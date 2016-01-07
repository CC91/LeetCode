// 5. Longest Palindromic Substring

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int n = s.size();
        string res = s.substr(0, 1);
        for (int i=0; i<n; i++) {
            string s1 = expand(s, i, i);
            if (s1.size()>res.size()) res = s1;
            string s2 = expand(s, i, i+1);
            if (s2.size()>res.size()) res = s2;
        }
        return res;
    }
    
    string expand(string s, int i, int j) {
        while (i>=0 && j<s.size() && s[i]==s[j]) {
            i--;
            j++;
        }
        return s.substr(i+1, j-i-1);
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        int maxLen = 1;
        int beginIdx = 0;
        bool L[1000][1000] = {false};
        
        for (int i=0; i<len; i++) L[i][i] = true;
        for (int i=0; i<len-1; i++) {
            if (s[i] == s[i+1]) {
                L[i][i+1] = true;
                maxLen = 2;
                beginIdx = i;
            }
        }
        
        for (int j=3; j<=len; j++ ) {
            for (int k=0; k<len-j+1; k++) {
                if (s[k] == s[k+j-1] && L[k+1][k+j-2]) {
                    L[k][k+j-1] = true;
                    maxLen = j;
                    beginIdx = k;
                }
            }
        }
        return s.substr(beginIdx, maxLen);
    }
};