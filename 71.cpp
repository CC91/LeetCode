// 71. Simplify Path

class Solution {
public:
    string simplifyPath(string path) {
        string res;
        stack<string> stk;
        while (!path.empty()) {
            if (path[0] == '/') {
                path = path.substr(1);
                continue;
            }
            
            int pos = path.find_first_of('/');
            string word;
            if (pos == -1) {
                word = path;
                path = "";
            } else {
                word = path.substr(0, pos);
                path = path.substr(pos + 1);
            }
            if (word == ".") continue;
            else if (word == "..") {
                if (!stk.empty()) stk.pop();
            } else stk.push(word);
        }
        while (!stk.empty()) {
            res = '/' + stk.top() + res;
            stk.pop();
        }
        return res.empty()?"/" : res;
    }
};