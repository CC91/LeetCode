// 244. Shortest Word Distance II

class WordDistance {
private:
    unordered_map<string, vector<int>> m;
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            m[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int res = INT_MAX;
        for (int i = 0; i < m[word1].size(); i++) {
            for (int j = 0; j < m[word2].size(); j++) {
                res = min(res, abs(m[word1][i] - m[word2][j]));
            }
        }
        return res;
    }
};


class WordDistance {
private:
    unordered_map<string, vector<int>> m;
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            m[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int i = 0;
        int j = 0;
        int res = INT_MAX;
        while (i < m[word1].size() && j < m[word2].size()) {
            res = min(res, abs(m[word1][i] - m[word2][j]));
            m[word1][i] < m[word2][j] ? i++ : j++;
        }
        return res;
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");