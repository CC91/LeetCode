// 41. First Missing Positive

class Solution {
public: // in place "hash table", align positives as a[i]=i+1
    int firstMissingPositive(vector<int>& nums) {
        int i = 0, n = nums.size();
        while (i<n) {
            if (nums[i]>0 && nums[i]<n && nums[i]!=i+1 && nums[i]!=nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);
            else i++;
        }
        for (int i=0; i<n; i++) {
            if (nums[i]!=i+1) return i+1;
        }
        return n+1;
    }
};


class Solution {
public: // use set (hash table)
    int firstMissingPositive(vector<int>& nums) {
        set<int> s;
        for (int n:nums) {
            if (n>0) s.insert(n);
        }
        for (int i=1; ; i++) {
            if (!s.count(i)) return i;
        }
    }
};