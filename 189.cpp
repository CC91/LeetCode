// 189. Rotate Array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        for (int i=0; i<k; i++) {
            nums.insert(nums.begin(), nums.back());
            nums.pop_back();
        }
    }
};


class Solution {
public: // http://www.cplusplus.com/reference/algorithm/reverse/
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.begin()+n-k); // reverse first n-k elements
        reverse(nums.begin()+n-k, nums.end()); // reverse last k elements
        reverse(nums.begin(), nums.end()); // reverse whole array
    }
};