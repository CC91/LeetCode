// 89. Gray Code

class Solution {
public: // reflect and prefix method, https://en.wikipedia.org/wiki/Gray_code
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        int t = 1;
        for (int i=1; i<=n; i++) {
            for (int j=res.size()-1; j>=0; j--) res.push_back(res[j]+t);
            t <<= 1;
        }
        return res;
    }
};


class Solution {
public: // math
    vector<int> grayCode(int n) {
        vector<int> res;
        int s = 1<<n;
        for (int i=0; i<s; i++) res.push_back(i^(i>>1));
        return res;
    }
};