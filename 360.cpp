// 360. Sort Transformed Array

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> res;
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto n : nums) {
            q.push(n * n * a + n * b + c);
        }
        while (!q.empty()) {
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};


class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> res(nums.size());
        int i = 0;
        int j = nums.size() - 1;
        int idx = a >= 0? nums.size() - 1 : 0;
        while (i <= j) {
            int m = nums[i] * nums[i] * a + nums[i] * b + c;
            int n = nums[j] * nums[j] * a + nums[j] * b + c;
            if (a >= 0) {
                if (m > n) {
                    res[idx--] = m;
                    i++;
                } else {
                    res[idx--] = n;
                    j--;
                }
            } else {
                if (m > n) {
                    res[idx++] = n;
                    j--;
                } else {
                    res[idx++] = m;
                    i++;
                }
            }
        }
        return res;
    }
};