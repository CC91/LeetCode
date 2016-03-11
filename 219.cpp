// 219. Contains Duplicate II

class Solution {
public: // hash table
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i=0; i<nums.size(); i++) {
            if (m.count(nums[i]) && i-m[nums[i]]<=k) return true;
            else m[nums[i]] = i;
        }
        return false;
    }
};


class Solution {
public: // set, second function in it
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> s;
        for (int i=0; i<nums.size(); i++) {
            if (i>k) s.erase(nums[i-k-1]);
            if (!s.insert(nums[i]).second) return true; // second func means trueif a new element was inserted or false if an equivalent element already existed
        }
        return false;
    }
};