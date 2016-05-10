// 347. Top K Frequent Elements

class Solution {
public: // priority queue
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> m;
        priority_queue<pair<int, int>> p;
        for (int n:nums) m[n]++;
        for (auto it:m) p.push({it.second, it.first});
        for (int i = 0; i < k; i++) {
            res.push_back(p.top().second);
            p.pop();
        }
        return res;
    }
};