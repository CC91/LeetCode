// 126. Word Ladder II

class Solution {
public:
    vector<vector<string>> res;
    unordered_map<string, vector<string>> m;
    vector<string> path;
    void findW(string str, unordered_set<string> &wordList, unordered_set<string> &nextL) {
        int n = str.size();
        string s = str;
        for (int i=0; i<n; i++) {
            s = str;
            for (char j='a'; j<='z'; j++) {
                s[i]=j;
                if (wordList.count(s)) {
                    nextL.insert(s);
                    m[s].push_back(str);
                }
            }
        }
    }
    
    void getPath(string beginWord, string endWord) {
        if (beginWord==endWord) {
            reverse(path.begin(), path.end());
            res.push_back(path);
            reverse(path.begin(), path.end());
        }else {
            for (int i=0; i<m[endWord].size(); i++) {
                path.push_back(m[endWord][i]);
                getPath(beginWord, m[endWord][i]);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        wordList.insert(beginWord);
        wordList.insert(endWord);
        unordered_set<string> curL;
        unordered_set<string> nextL;
        curL.insert(beginWord);
        path.push_back(endWord);
        while (1) {
            for (auto it=curL.begin(); it!=curL.end(); it++) wordList.erase(*it);
            for (auto it=curL.begin(); it!=curL.end(); it++) findW(*it, wordList, nextL);
            if (nextL.empty()) return res;
            if (nextL.find(endWord)!=nextL.end()) {
                getPath(beginWord, endWord);
                return res;
            }
            swap(curL, nextL);
            nextL.clear();
        }
        return res;
    }
};