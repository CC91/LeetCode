// 35. Search Insert Position

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        nums.push_back(target);
        sort(nums.begin(), nums.end());
        int pos = find(nums.begin(), nums.end(), target)-nums.begin();
        return pos;
    }
};


class Solution {
public: // binary search
    int searchInsert(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        while (i<=j) {
            int m = (i+j)>>1;
            if (nums[m]==target) return m;
            else if (nums[m]>target) j = m-1;
            else i = m+1;
        }
        return i;
    }
};