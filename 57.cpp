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
public: // 3 cases: newI<intervals (a), newI overlap with intervals (b), newI after intervals (c)
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        auto it = intervals.begin();
        for (; it!=intervals.end(); it++) {
            if (newInterval.end<(*it).start) break; // case a
            else if (newInterval.start>(*it).end) res.push_back(*it); // case c
            else {
                newInterval.start = min(newInterval.start, (*it).start); // case b
                newInterval.end = max(newInterval.end, (*it).end);
            }
        }
        res.push_back(newInterval);
        for (; it!=intervals.end(); it++) res.push_back(*it);
        return res;
    }
};