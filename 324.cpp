// 324. Wiggle Sort II

class Solution {
public: // M, S, S, S; L, L, L, M. Combine. 
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        auto midptr = nums.begin()+n/2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        
        #define A(i) nums[(1+2*i) % (n|1)]
        
        int i = 0, j = 0, k = n-1;
        while (j<=k) {
            if (A(j)<mid) swap(A(j), A(k--)); // smaller val move to the backward of mid
            else if (A(j)>mid) swap(A(i++), A(j++)); // bigger val move in front of M
            else j++;
        }
    }
};