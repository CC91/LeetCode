// 423. Reconstruct Original Digits from English

class Solution {
public:
    string originalDigits(string s) {
        string res = "";
        vector<string> base{"zero", "two", "four", "six", "eight", "one",
        	"three", "five", "seven", "nine"};
        vector<int> nums{0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
        vector<char> identifier{'z', 'w', 'u', 'x', 'g', 
        	'o', 'h', 'f', 's', 'i'};
        int m[126] = {0};
        for (auto a : s) {
            m[a]++;
        }
        for (int i = 0; i < 10; i++) {
            int cnt = m[identifier[i]];
            if (!cnt) {
                continue;
            }
            for (int j = 0; j < base[i].size(); j++) {
                m[base[i][j]] -= cnt;
            }
            while (cnt--) {
                res += nums[i] + '0';
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};