// 20. Valid Parentheses

class Solution {
public: // In STL, if use stack.pop(), the precondition is that the stack is not empty! So we need to check the stack first!
    bool isValid(string s) {
        if (s.empty()) return false;
        stack<char> stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') stk.push(s[i]);
            else if (s[i] == ')' && !stk.empty() && stk.top() == '(') stk.pop();
            else if (s[i] == '}' && !stk.empty() && stk.top() == '{') stk.pop();
            else if (s[i] == ']' && !stk.empty() && stk.top() == '[') stk.pop();
            else return false;
        }
        return stk.empty();
    }
};