// 303. Range Sum Query - Immutable

class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int> &nums) {
        sum.push_back(0);
        for (int n : nums) {
            sum.push_back(sum.back() + n);
        }
    }

    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);