// 452. Minimum Number of Arrows to Burst Balloons

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if (points.empty()) {
            return 0;
        }
        sort(points.begin(), points.end(), 
        	[](pair<int, int> a, pair<int, int>b)
        		{return a.first == b.first ? 
        			a.second > b.second : a.first < b.first;});
        int res = 1;
        int bound = points[0].second;
        for (int i = 1; i < points.size(); i++) {
            if (points[i].first <= bound) {
                bound = min(bound, points[i].second);
            } else {
                res++;
                bound = points[i].second;
            }
        }
        return res;
    }
};