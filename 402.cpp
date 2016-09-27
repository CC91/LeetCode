// 402. Remove K Digits

class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        int len = num.size() - k;
        for (auto a : num) {
            while (k && res.size() && res.back() > a) {
                res.pop_back();
                k--;
            }
            res.push_back(a);
        }
        res.resize(len);
        while (res.size() > 1 && res[0] == '0') {
            res.erase(res.begin());
        }
        return res.empty() ? "0" : res;
    }
};