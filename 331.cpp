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