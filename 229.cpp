// 229. Majority Element II

class Solution { // Moore voting
public: // There are at most x majority element in the array where x*(n/3+1)<=n, x*(1/3+1/n)<=1, x is at most 2
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        int n1 = 0, n2 = 0, cnt1 = 0, cnt2 = 0;
        for (int a:nums) {
            if (a==n1) cnt1++;
            else if (a==n2) cnt2++;
            else if (cnt1==0) n1 = a, cnt1 = 1;
            else if (cnt2==0) n2 = a, cnt2 = 1;
            else cnt1--, cnt2--;
        }
        cnt1 = cnt2 = 0;
        for (int b:nums) {
            if (b==n1) cnt1++;
            else if (b==n2) cnt2++;
        }
        if (cnt1>n/3) res.push_back(n1);
        if (cnt2>n/3) res.push_back(n2);
        return res;
    }
};