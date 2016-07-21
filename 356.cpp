// 356. Line Reflection

class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        if (points.empty()) {
            return true;
        }
        sort(points.begin(), points.end());
        double x = (points[0].first + points.back().first) / 2.0;
        unordered_map<int, set<int>> m;
        for (auto a : points) {
            m[a.first].insert(a.second);
        }
        for (auto a : points) {
            if (!m[2 * x - a.first].count(a.second)) {
                return false;
            }
        }
        return true;
    }
};