// 57. Insert Interval

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
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        bool isInsert = false;
        for (int i=0; i<intervals.size(); i++) {
            if (isInsert) {
                res.push_back(intervals[i]);
                continue;
            }
            
            if (newInterval.end < intervals[i].start) {
                res.push_back(newInterval);
                res.push_back(intervals[i]);
                isInsert = true;
                continue;
            }
            
            if (newInterval.start <= intervals[i].end && intervals[i].start <= newInterval.end) {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
                continue;
            }
            res.push_back(intervals[i]);
        }
        if (!isInsert) res.push_back(newInterval);
        return res;
    }
};