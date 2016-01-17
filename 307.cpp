// 307. Range Sum Query - Mutable

class NumArray {
private: // http://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/
    int s;
    vector<int> num;
    vector<int> sum;
    
public:
    NumArray(vector<int> &nums) {
        s = nums.size();
        num = vector<int> (s+1, 0);
        sum = vector<int> (s+1, 0);
        for (int i=0; i<s; i++) update(i, nums[i]);
    }

    void update(int i, int val) {
        int old = num[i+1];
        for (int j=i+1; j<=s; j+=j&(-j)) sum[j]=sum[j]-old+val;
        num[i+1] = val;
    }

    int sumRange(int i, int j) {
        return getSum(j+1)-getSum(i);
    }
    
    int getSum(int idx) {
        int res = 0;
        for (int i=idx; i>0; i-=i&(-i)) res += sum[i];
        return res;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
