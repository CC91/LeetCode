// 164. Maximum Gap

class Solution {
public: // Naive, nlgn
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int res = INT_MIN;
        for (int i = 1; i < nums.size(); i++) {
            res = max(res, abs(nums[i] - nums[i - 1]));
        }
        return res;
    }
};



class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        int res = 0;
        int minNum = nums[0];
        int maxNum = nums[0];
        for (int n : nums) {
            minNum = min(minNum, n);
            maxNum = max(maxNum, n);
        }
        if (minNum == maxNum) {
            return 0;
        }
        int interval = (maxNum - minNum) / nums.size() + 1;
        int numBucket = (maxNum - minNum) / interval + 1;
        vector<vector<int>> bucket(numBucket, vector<int> {INT_MAX, INT_MIN});
        for (int n : nums) {
            int i = (n - minNum) / interval;
            if (n < bucket[i][0]) {
                bucket[i][0] = n;
            }
            if (n > bucket[i][1]) {
                bucket[i][1] = n;
            }
        }
        int first = bucket[0][1];
        int second;
        for (int i = 1; i < numBucket; i++) {
            if (bucket[i][0] == INT_MAX) {  // bucket might be empty
                continue;
            }
            second = bucket[i][0];
            res = max(res, second - first);
            first = bucket[i][1];
        }
        return res;
    }
};