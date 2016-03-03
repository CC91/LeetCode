 // 56. Merge Intervals

 /**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public: // define a comparison operator
    struct comp {
        bool operator() (Interval a, Interval b) {
            return a.start<b.start;
        }
    };
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), comp()); // comparison
        for (int i=0; i<intervals.size(); i++) {
            if (res.empty() ||res.back().end<intervals[i].start) res.push_back(intervals[i]);
            else res.back().end = max(res.back().end, intervals[i].end);
        }
        return res;
    }
};
