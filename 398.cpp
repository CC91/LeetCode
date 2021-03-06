// 398. Random Pick Index

class Solution {
public:
    Solution(vector<int> nums) {
        v = nums;
    }
    
    int pick(int target) {
        int res = -1;
        int cnt = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] != target) {
                continue;
            } 
            cnt++;
            if (rand() % cnt == 0) {
                res = i;
            }
        }
        return res;
    }

private:
    vector<int> v;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */