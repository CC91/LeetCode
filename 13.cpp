// 13. Roman to Integer

class Solution {
public: // hash map
    int romanToInt(string s) {
        unordered_map<char, int> m({{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}});
        int res = 0;
        for (int i=0; i<s.size(); i++) {
            res += m[s[i]];
            if (i>0 && m[s[i]]>m[s[i-1]]) res -= 2*m[s[i-1]];
        }
        return res;
    }
};


class Solution {
public:
    int romanToInt(string s) {
        int len = s.size();
        int res = helper(s[len-1]);
        for (int i=len-2; i>=0; i--) {
            int a = helper(s[i+1]), b = helper(s[i]);
            if (a<=b) res += b;
            else res -= b;
        }
        return res;
    }
    
    int helper(char c) {
        int val = 0;
        switch(c) {
            case 'I': val = 1; break;
            case 'V': val = 5; break;
            case 'X': val = 10; break;
            case 'L': val = 50; break;
            case 'C': val = 100; break;
            case 'D': val = 500; break;
            case 'M': val = 1000; break;
        }
        return val;
    }
};