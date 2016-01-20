// 4. Median of Two Sorted Arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int len = m+n;
        if (len%2==1) {
            return findK(nums1.begin(), m, nums2.begin(), n, len/2+1);
        } else return (findK(nums1.begin(), m, nums2.begin(), n, len/2)+findK(nums1.begin(), m, nums2.begin(), n, len/2+1))/2;
    }
    
    double findK(vector<int>::iterator it1, int m, vector<int>::iterator it2, int n, int k) {
        if (m>n) return findK(it2, n, it1, m, k);
        if (m==0) return *(it2+k-1);
        if (k==1) return min(*it1, *it2);
        int pa = min(m, k/2);
        int pb = k-pa;
        if (*(it1+pa-1)<*(it2+pb-1)) return findK(it1+pa, m-pa, it2, n, k-pa);
        else if (*(it1+pa-1)>*(it2+pb-1)) return findK(it1, m, it2+pb, n-pb, k-pb);
        else return *(it1+pa-1);
    }
};