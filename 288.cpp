// 288. Unique Word Abbreviation

class ValidWordAbbr {
private:
    unordered_map<string, set<string>> m;
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (auto &a : dictionary) {
            string t = a[0] + to_string(a.size() - 2) + a.back();
            m[t].insert(a);
        }
    }

    bool isUnique(string word) {
        string t = word[0] + to_string(word.size() - 2) + word.back();
        return m[t].size() == m[t].count(word);
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");