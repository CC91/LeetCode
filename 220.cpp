// 220. Contains Duplicate III

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        vector<pair<long, long>> p(n);
        for (int i=0; i<n; i++) p[i] = pair<long, long> (nums[i], i);
        sort(p.begin(), p.end());
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n && p[j].first-p[i].first<=t; j++) {
                if (abs(p[j].second-p[i].second)<=k) return true;
            }
        }
        return false;
    }
};