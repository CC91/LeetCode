// 354. Russian Doll Envelopes

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.empty()) {
            return 0;
        }
        sort(envelopes.begin(), envelopes.end());
        int res = 1;
        int n = envelopes.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (envelopes[j].first < envelopes[i].first && 
                		envelopes[j].second < envelopes[i].second) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};


class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.empty()) {
            return 0;
        }
        sort(envelopes.begin(), envelopes.end(),[](pair<int, int> a, 
        		pair<int, int> b) {return a.first == b.first ? 
        			a.second > b.second : a.first < b.first;} );
        vector<int> res;
        for (auto a : envelopes) {
            int left = 0;
            int right = res.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (res[mid] < a.second) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            if (left == res.size()) {
                res.push_back(a.second);
            } else {
                res[left] = a.second;
            }
        }
        return res.size();
    }
};