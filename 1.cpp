// 1. Two Sum

class Solution {
public:// brute force
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for (int i=0; i<nums.size()-1; i++) {
            for (int j=i+1; j<nums.size(); j++) {
                if (nums[i]+nums[j]==target) {
                    res.push_back(i+1);
                    res.push_back(j+1);
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        int a = 0, b = tmp.size()-1;
        while (a<b) {
            if (tmp[a]+tmp[b]<target) a++;
            else if (tmp[a]+tmp[b]>target) b--;
            else break;
        }
        
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]==tmp[a] ||nums[i]==tmp[b]) res.push_back(i+1);
        }
        if (res[0]>res[1]) swap(res[0], res[1]);
        return res;
    }
};