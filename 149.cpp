// 149. Max Points on a Line

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int res = 0;
        for (int i=0; i<points.size(); i++) {
            int nMax = 0, nSame = 0, nInf = 0;
            unordered_map<float, int> slopes;
            for (int j=i+1; j<points.size(); j++) {
                if (points[j].x==points[i].x) {
                    if (points[j].y==points[i].y) nSame++;
                    else nInf++;
                    continue;
                }
                float slp = (float)(points[j].y-points[i].y)/(float)(points[j].x-points[i].x);
                slopes[slp]++;
                nMax = max(nMax, slopes[slp]);
            }
            nMax = max(nMax, nInf)+nSame+1;
            res = max(nMax, res);
        }
        return res;
    }
};