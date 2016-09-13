// 394. Decode String

class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return helper(s, i);
    }
    
    string helper(string s, int &i) {
        int n = s.size();
        string res = "";
        while (i < n && s[i] != ']') {
            if (s[i] > '9') {
                res += s[i++];
            } else {
                int cnt = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    cnt = cnt * 10 + s[i++] - '0';
                }
                i++;
                string t = helper(s, i);
                i++;
                while (cnt-- > 0) {
                    res += t;
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    string decodeString(string s) {
        string res = "";
        stack<int> num;
        stack<string> str;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                cnt = cnt * 10 + s[i] - '0';
            } else if (s[i] == '[') {
                num.push(cnt);
                str.push(res);
                cnt = 0;
                res.clear();
            } else if (s[i] == ']') {
                int k = num.top();
                num.pop();
                while (k-- > 0) {
                    str.top() += res;
                }
                res = str.top();
                str.pop();
            } else {
                res += s[i];
            }
        }
        return res;
    }
};