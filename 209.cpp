// 209. Minimum Size Subarray Sum

class Solution {
public: // O(n) time, sliding window check sum subarray length
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0, end = 0, sum = 0, len = nums.size(), res = len+1;
        while (end<len) {
            while (end<len && sum<s) sum += nums[end++];
            while (sum>=s) {
                res = min(res, end-start);
                sum -= nums[start++];
            }
        }
        return res==len+1?0:res;
    }
};


class Solution {
public: // binary search, use sums[i] to store [0, i-1] sums
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size(), res = len+1, sums[len+1] = {0};
        for (int i=1; i<len+1; i++) sums[i] = sums[i-1]+nums[i-1];
        for (int i=0; i<len+1; i++) {
            int right = search(i+1, len, sums[i]+s, sums); //sums[i]+s covers the subarray whose sum>=7, find the right bound of it
            if (right==len+1) break;
            else res = min(res, right-i);
        }
        return res==len+1?0:res;
    }
    
    int search(int i, int j, int target, int sums[]) {
        while (i<=j) {
            int mid = i+(j-i)/2;
            if (sums[mid]>=target) j = mid-1;
            else i = mid+1;
        }
        return i;
    }
};