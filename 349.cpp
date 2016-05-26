// 349. Intersection of Two Arrays

class Solution {
public: // 2 pointers and set
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0;
        int j = 0;
        set<int> s;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;
            }
            else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                s.insert(nums1[i]);
                i++;
                j++;
            }
        }
        return vector<int> (s.begin(), s.end());
    }
};