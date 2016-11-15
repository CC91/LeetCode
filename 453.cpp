// 453. Minimum Moves to Equal Array Elements

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minn = *min_element(nums.begin(), nums.end());
        int res = 0;
        for (auto a : nums) {
            res += a - minn;
        }
        return res;
    }
};