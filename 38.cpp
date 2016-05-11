// 38. Count and Say

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1 || n == 2) return n == 1? "1" : "11";
        string res = "11";
        for (int i = 3; i <= n; i++) {
            int len = res.size();
            string tmp = "";
            int cnt = 1;
            for (int j = 1; j < len + 1; j++) {
                if (res[j] != res[j-1]) {
                    tmp += to_string(cnt);
                    tmp += res[j-1];
                    cnt = 1;
                } else {
                    cnt++;
                }
            }
            res = tmp;
        }
        return res;
    }
};