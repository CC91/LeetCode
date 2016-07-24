 // 370. Range Addition

 class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length + 1, 0);
        for (auto a : updates) {
            res[a[0]] += a[2];
            res[a[1] + 1] -= a[2];
        }
        for (int i = 1; i < length; i++) {
            res[i] += res[i - 1];
        }
        res.pop_back();
        return res;
    }
};