// 27. Remove Element

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (int i=0; i<nums.size();) {
            if (nums[i]==val) nums.erase(nums.begin()+i);
            else i++;
        }
        return nums.size();
    }
};


class Solution {
public: // https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom
    int removeElement(vector<int>& nums, int val) {
        nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }
};


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for (int n:nums) {
            if (n!=val) nums[i++] = n;
        }
        return i;
    }
};