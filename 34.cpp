// 34. Search for a Range

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        if (find(nums.begin(), nums.end(), target)==nums.end()) {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        int idx = find(nums.begin(), nums.end(), target)-nums.begin();
        res.push_back(idx);
        while (idx+1<nums.size() && nums[idx+1]==target) idx++;
        res.push_back(idx);
        return res;
    }
};


class Solution {
public: // multiset
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        multiset<int> m;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]==target) m.insert(i);
        }
        if (!m.empty()) {
            res.push_back(*m.begin());
            res.push_back(*m.rbegin()); // *m.end() doesn't work because it points to the element next to the last
            return res;
        }
        return {-1, -1};
    }
};


class Solution {
public: // binary search
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = findL(nums, target), r = findR(nums, target);
        return {l, r};
    }
    
    int findL(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while (l<r) {
            int m = (l+r)>>1;
            if (nums[m]<target) l = m+1;
            else r = m;
        }
        return nums[l]==target?l:-1;
    }
    
    int findR(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while (l<r) {
            int m = 1+(l+r)>>1; // notice that m changes on the right part
            if (nums[m]<=target) l = m;
            else r = m-1;
        }
        return nums[l]==target?l:-1;
    }
};