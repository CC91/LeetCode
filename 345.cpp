// 345. Reverse Vowels of a String

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        set<char> st{'a', 'e', 'i', 'o', 'u'};
        while (i < j) {
            if (!st.count(tolower(s[i]))) {
                i++;
                continue;
            }
            if (!st.count(tolower(s[j]))) {
                j--;
                continue;
            }
            swap(s[i++], s[j--]);
        }
        return s;
    }
};