// 217. Contains Duplicate

class Solution {
public: // sort and brute force
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty()) return false;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size()-1; i++) {
            if (nums[i]==nums[i+1]) return true;
        }
        return false;
    }
};


class Solution {
public: // set
    bool containsDuplicate(vector<int>& nums) {
        return set<int>(nums.begin(), nums.end()).size()<nums.size();
    }
};