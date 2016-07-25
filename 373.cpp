// 373. Find K Pairs with Smallest Sums

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        int m = nums1.size();
        int n = nums2.size();
        for (int i = 0; i < min(m, k); i++) {
            for (int j = 0; j < min(n, k); j++) {
                res.push_back({nums1[i], nums2[j]});
            }
        }
        sort(res.begin(), res.end(), [](pair<int, int> a, pair<int, int> b) 
        		{return a.first + a.second < b.first + b.second;});
        while (res.size() > k) {
            res.pop_back();
        }
        return res;
    }
};


class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        auto cmp = [](pair<int, int> a, pair<int, int> b) 
        	{return a.first + a.second < b.first + b.second;};
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
        	decltype(cmp)> q(cmp);
        int m = nums1.size();
        int n = nums2.size();
        for (int i = 0; i < min(m, k); i++) {
            for (int j = 0; j < min(n, k); j++) {
                if (q.size() < k) {
                    q.push({nums1[i], nums2[j]});
                } else if (nums1[i] + nums2[j] < 
                		q.top().first + q.top().second) {
                    q.pop();
                    q.push({nums1[i], nums2[j]});
                }
            }
        }
        while (!q.empty()) {
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};

