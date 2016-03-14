// 287. Find the Duplicate Number

class Solution {
public: // binary search, http://bookshadow.com/weblog/2015/09/28/leetcode-find-duplicate-number/
    int findDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        while (low<=high) {
            int mid = low+(high-low)/2;
            int cnt = 0;
            for (int n:nums) {
                if (n<=mid) cnt++;
            }
            if (cnt<=mid) low = mid+1;
            else high = mid-1;
        }
        return low;
    }
};