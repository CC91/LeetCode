// 58. Length of Last Word

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        int res = 0;
        int n = s.size();
        int i = n - 1;
        while (i >= 0) {
            if (s[i] != ' ') break;
            i--;
        }
        for (i; i >= 0; i--) {
            if (s[i] != ' ') res++;
            else break;
        }
        return res;
    }
};


class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.find_last_not_of(' '); // find the position of the last letter
        return (i == string::npos)? 0 : (i - s.find_last_of(' ', i)); // find ' ' before position i
    }
};