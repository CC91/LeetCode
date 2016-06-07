// 331. Verify Preorder Serialization of a Binary Tree

class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.empty()) {
            return false;
        }
        int count = 1;
        string s;
        vector<string> tmp;
        istringstream iss(preorder);
        while(getline(iss, s, ',')) {
            tmp.push_back(s);
        }
        for (string t : tmp) {
            count--;
            if (count < 0) {
                return false;
            }
            if (t != "#") {
                count += 2;
            }
        }
        return count == 0;
    }
};



class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.empty()) {
            return false;
        }
        stack<string> s;
        istringstream iss(preorder);
        vector<string> tmp;
        string str;
        while (getline(iss, str, ',')) {
            tmp.push_back(str);
        }
        for (string t : tmp) {
            if (t == "#") {
                while (!s.empty() && s.top() == "#") {
                    s.pop();
                    if (s.empty() || s.top() == "#") {
                        return false;
                    }
                    s.pop();
                }
                s.push("#");
            } else {
                s.push(t);
            }
        }
        return s.size() == 1 && s.top() == "#";
    }
};