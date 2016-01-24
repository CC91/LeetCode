// 32. Longest Valid Parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        const char* str = s.c_str();
        const char *p = str;
        vector<const char*> stk;
        long res = 0;
        while (*p!='\0') {
            if (*p=='(') stk.push_back(p);
            else {
                if (!stk.empty() && *stk.back()=='(') {
                    stk.pop_back();
                    res = max(res, p-(stk.empty()?str-1:stk.back()));
                } else stk.push_back(p);
            }
            p++;
        }
        return res;
    }
};