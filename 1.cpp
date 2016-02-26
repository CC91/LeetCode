// 1. Two Sum

class Solution {
public: // hash table
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> m;
        for (int i=0; i<nums.size(); i++) {
            if (m.count(target-nums[i])) {
                res.push_back(m[target-nums[i]]);
                res.push_back(i);
                return res;
            } else m[nums[i]]=i;
        }
    }
};


class Solution {
public: // brute force
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for (int i=0; i<nums.size()-1; i++) {
            for (int j=i+1; j<nums.size(); j++) {
                if (nums[i]+nums[j]==target) {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
    }
};