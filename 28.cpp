// 28. Implement strStr()

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int h = haystack.size(), n = needle.size(), i = 0;
        while (i<h) {
            if (haystack[i]==needle[0]) {
                string tmp = haystack.substr(i, n);
                if (tmp==needle) return i;
            }
            i++;
        }
        return -1;
    }
};


class Solution {
public:
    int strStr(string haystack, string needle) {
        int res = haystack.find(needle);
        return res;
    }
};