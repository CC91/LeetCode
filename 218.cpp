// 218. The Skyline Problem

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> boundary, res;
        multiset<int> h;
        int pre = 0, cur = 0;
        for (auto a:buildings) {
            boundary.push_back({a[0], -a[2]});
            boundary.push_back({a[1], a[2]});
        }
        sort(boundary.begin(), boundary.end());
        h.insert(0);
        for (auto a:boundary) {
            if (a.second<0) h.insert(-a.second);
            else h.erase(h.find(a.second));
            cur = *h.rbegin();
            if (cur!=pre) {
                res.push_back({a.first, cur});
                pre = cur;
            }
        }
        return res;
    }
};