// 28. Implement strStr()

class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};


class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (haystack.empty()) return -1;
        int h = haystack.size(), n = needle.size();
        for (int i=0; i<=h-n; i++) {
            if (haystack[i]==needle[0]) {
                string tmp = haystack.substr(i, n);
                if (tmp==needle) return i;
            }
        }
        return -1;
    }
};


class Solution {
public: // 2 pointers
    int strStr(string haystack, string needle) {
        int i = 0, j = 0;
        while (haystack[i] && needle[j]) {
            if (haystack[i]==needle[j]) {
                i++;
                j++;
            } else {
                i = i-j+1;
                j = 0;
            }
        }
        return needle[j]?-1:(i-j);
    }
};