// 151. Reverse Words in a String

class Solution {
public:
    void reverseWords(string &s) {
        string res;
        int right_space = s.size();
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ') right_space = i;
            else if (s[i - 1] == ' ' || i == 0) {
                if (!res.empty()) res += ' ';
                res += s.substr(i, right_space - i);
            }
        }
        s = res;
    }
};