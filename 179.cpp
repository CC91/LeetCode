// 179. Largest Number

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        vector<string> sortedArr;
        for (int n:nums) sortedArr.push_back(to_string(n));
        sort(sortedArr.begin(), sortedArr.end(), [](string &s1, string &s2) {return s1+s2>s2+s1; });
        for (string s:sortedArr) res += s;
        while (res[0]=='0' && res.size()>1) res.erase(0, 1);
        return res;
    }
};