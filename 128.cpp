// 128. Longest Consecutive Sequence

class Solution {
public: // each time search smaller numbers of the cur value and larger numbers of it
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        int maxLen = 1;
        unordered_set<int> s;
        for (int n:nums) s.insert(n);
        for (int i=0; i<nums.size(); i++) {
            if (s.empty()) break;
            int curNum = nums[i], curLen = 0;
            while (s.count(curNum)) {
                s.erase(curNum);
                curNum++;
                curLen++;
            }
            curNum = nums[i]-1;
            while (s.count(curNum)) {
                s.erase(curNum);
                curNum--;
                curLen++;
            }
            maxLen = max(maxLen, curLen);
        }
        return maxLen;
    }
};