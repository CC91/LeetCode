// 414. Third Maximum Number

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN;
        long second = LONG_MIN;
        long third = LONG_MIN;
        for (auto a : nums) {
            if (a > first) {
                third = second;
                second = first;
                first = a;
            } else if (a > second && a < first) {
                third = second;
                second = a; 
            } else if (a > third && a < second) {
                third = a;
            }
        }
        return third == LONG_MIN ? first : third;
    }
};


class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for (auto a : nums) {
            s.insert(a);
            if (s.size() > 3) {
                s.erase(s.begin());
            }
        }
        return s.size() == 3 ? *s.begin() : *s.rbegin();
    }
};