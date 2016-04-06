// 290. Word Pattern

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> m1;
        unordered_map<string, int> m2;
        istringstream s(str);
        int i = 0;
        for (string word; s>>word; i++) {
            if (m1.count(pattern[i]) ||m2[word]) {
                if (m1[pattern[i]]!=m2[word]) return false; 
            } else m1[pattern[i]]=m2[word]=i+1;
        }
        return i==pattern.size();
    }
};