// 391. Perfect Rectangle

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        set<string> s;
        int min_x = INT_MAX;
        int min_y = INT_MAX;
        int max_x = INT_MIN;
        int max_y = INT_MIN;
        int area = 0;
        for (auto a : rectangles) {
            min_x = min(min_x, a[0]);
            min_y = min(min_y, a[1]);
            max_x = max(max_x, a[2]);
            max_y = max(max_y, a[3]);
            area += (a[2] - a[0]) * (a[3] - a[1]);
            string s1 = to_string(a[0]) + "_" + to_string(a[1]);
            string s2 = to_string(a[0]) + "_" + to_string(a[3]);
            string s3 = to_string(a[2]) + "_" + to_string(a[3]);
            string s4 = to_string(a[2]) + "_" + to_string(a[1]);
            if (s.count(s1)) {
                s.erase(s1);
            } else {
                s.insert(s1);
            }
            if (s.count(s2)) {
                s.erase(s2);
            } else {
                s.insert(s2);
            }
            if (s.count(s3)) {
                s.erase(s3);
            } else {
                s.insert(s3);
            }
            if (s.count(s4)) {
                s.erase(s4);
            } else {
                s.insert(s4);
            }
        }
        string t1 = to_string(min_x) + "_" + to_string(min_y);
        string t2 = to_string(min_x) + "_" + to_string(max_y);
        string t3 = to_string(max_x) + "_" + to_string(max_y);
        string t4 = to_string(max_x) + "_" + to_string(min_y);
        if (!s.count(t1) || !s.count(t2) || !s.count(t3) 
            || !s.count(t4) || s.size() != 4) {
            return false;
        }
        return area == (max_x - min_x) * (max_y - min_y);
    }
};