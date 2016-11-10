// 451. Sort Characters By Frequency

class Solution {
public:
    string frequencySort(string s) {
        int m[256] = {0};
        for (auto &a : s) {
            m[a]++;
        }
        sort(s.begin(), s.end(), [&m](char a, char b) {
            return m[a] > m[b] || m[a] == m[b] && a < b;});
        return s;
    }
};