// 169. Majority Element

class Solution {
public: // hash map
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        for (int n:nums) m[n] += 1;
        for (auto it=m.begin(); it!=m.end(); it++) {
            if (it->second>nums.size()/2) return it->first;
        }
    }
};


class Solution {
public: // use cnt and res to record the cur situation
    int majorityElement(vector<int>& nums) {
        int res = nums[0], cnt = 0, n = nums.size();
        for (int i=0; i<n; i++) {
            if (cnt==0 ||res==nums[i]) {
                res = nums[i];
                cnt++;
            } else cnt--;
        }
        return res;
    }
};


class Solution { // O(n) time, O(1) space
public: // since majority element appears >= n/2, we could use a cnt to counteract non-majority element
    int majorityElement(vector<int>& nums) {
        int cnt = 0, n = nums.size(), res = nums[0];
        for (int i=0; i<nums.size(); i++) {
            if (cnt==0 ||res==nums[i]) {
                res = nums[i];
                cnt++;
            } else cnt--;
        }
    }
};