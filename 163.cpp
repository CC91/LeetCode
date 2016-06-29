// 163. Missing Ranges

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        int l = lower;
        int r;
        for (int i = 0; i <= nums.size(); i++) {
            r = (i < nums.size() && nums[i] <= upper) ? nums[i] : upper + 1;
            if (l == r) {
                l++;
            } else if (l < r) {
                res.push_back(r - l == 1 ? to_string(l) : to_string(l) + "->" + to_string(r - 1));
                l = r + 1;
            }
        }
        return res;
    }
};