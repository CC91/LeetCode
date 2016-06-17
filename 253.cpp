// 253. Meeting Rooms II

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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> s(intervals.size());
        vector<int> e(intervals.size());
        int res = 0;
        int pos = 0;
        for (int i = 0; i < intervals.size(); i++) {
            s[i] = intervals[i].start;
            e[i] = intervals[i].end;
        }
        sort(s.begin(), s.end());
        sort(e.begin(), e.end());
        for (int i = 0; i < intervals.size(); i++) {
            if (s[i] < e[pos]) {
                res++;
            } else {
                pos++;
            }
        }
        return res;
    }
};


class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start < b.start;});
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto a : intervals) {
            if (!q.empty() && q.top() <= a.start) {
                q.pop();
            }
            q.push(a.end);
        }
        return q.size();
    }
};