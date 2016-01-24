// 327. Count of Range Sum

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int res = 0, i;
        multiset<long long> s;
        s.insert(0);
        long long sum=0;
        for (i=0; i<nums.size(); i++) {
            sum += nums[i];
            res += distance(s.lower_bound(sum-upper), s.upper_bound(sum-lower));
            s.insert(sum);
        }
        return res;
    }
};