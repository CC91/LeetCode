// 128. Longest Consecutive Sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        int res = 1;
        unordered_set<int> s;
        for (int n:nums) s.insert(n);
        for (int i=0; i<nums.size(); i++) {
            if (s.empty()) break;
            int curLen = 0, curNum = nums[i];
            while (s.count(curNum)) {
                s.erase(curNum);
                curLen++;
                curNum++;
            }
            curNum = nums[i]-1;
            while (s.count(curNum)) {
                s.erase(curNum);
                curLen++;
                curNum--;
            }
            res = max(res, curLen);
        }
        return res;
    }
};