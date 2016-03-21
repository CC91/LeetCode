// 18. 4Sum

class Solution {
public: // given 2 numbers, do 2sum to the rest of numbers
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        if (n<4) return res;
        sort(nums.begin(), nums.end());
        for (int i=0; i<n-3; i++) {
            if (i>0 && nums[i]==nums[i-1]) continue; // avoid duplicates
            for (int j=i+1; j<n-2; j++) {
                if (j>i+1 && nums[j]==nums[j-1]) continue;
                int start = j+1, end = n-1;
                int target2 = target-nums[i]-nums[j];
                while (start<end) {
                    int tmp = nums[start]+nums[end];
                    if (tmp<target2) start++;
                    else if (tmp>target2) end--;
                    else {
                        res.push_back(vector<int> {nums[i], nums[j], nums[start], nums[end]});
                        start++;
                        end--;
                        while (nums[start]==nums[start-1]) start++; // avoid duplicates
                        while (nums[end]==nums[end+1]) end--;
                    }
                }
            }
        }
        return res;
    }
};


class Solution {
public: // hash map, https://leetcode.com/discuss/3950/tle-on-4sum-using-hashtable
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        unordered_map<int, set<pair<int, int>>> m;
        set<vector<int>> res;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) { // check map first
                int a = nums[i]+nums[j];
                if (m.count(target-a)) {
                    for (auto p:m[target-a]) {
                        vector<int> b = {p.first, p.second, nums[i], nums[j]};
                        res.insert(b);
                    }
                }
            }
            for (int j=0; j<i; j++) { // then insert pair to the map in order to avoid duplicate elements in the solution
                int a = nums[j], b = nums[i];
                m[a+b].insert(make_pair(a, b));
            }
        }
        return vector<vector<int>> (res.begin(), res.end());
    }
};