// 447. Number of Boomerangs

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<int, int> m;
            for (int j = 0; j < points.size(); j++) {
                int x = points[i].first - points[j].first;
                int y = points[i].second - points[j].second;
                m[x * x + y * y]++;
            }
            for (auto a : m) {
                res += a.second * (a.second - 1);
            }
        }
        return res;
    }
};