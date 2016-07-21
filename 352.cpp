// 352. Data Stream as Disjoint Intervals

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        auto it = lower_bound(v.begin(), v.end(), Interval(val, val), 
        		[](Interval a, Interval b){return a.start < b.start; });
        if (it != v.begin() && (it - 1) -> end + 1 >= val) {
            it--;
        }
        int s = val;
        int e = val;
        while (it != v.end() && val + 1 >= it -> start && val - 1 <= it -> end) {
            s = min(s, it -> start);
            e = max(e, it -> end);
            it = v.erase(it);
        }
        v.insert(it, Interval(s, e));
    }
    
    vector<Interval> getIntervals() {
        return v;
    }

private:
    vector<Interval> v;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */