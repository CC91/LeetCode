// 313. Super Ugly Number

class Solution {
public: // http://bookshadow.com/weblog/2015/12/03/leetcode-super-ugly-number/
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int s = primes.size();
        vector<int> res(n), idx(s), vals(s); // idx vector if the multiplication times for each prime number
        res[0] = 1;
        for (int i=1; i<n; i++) {
            for (int j=0; j<s; j++) {
                vals[j] = res[idx[j]]*primes[j];
            }
            res[i] = *min_element(vals.begin(), vals.end());
            for (int k=0; k<s; k++) {
                if (res[i]==vals[k]) idx[k]++;
            }
        }
        return res.back();
    }
};


class Solution {
public: // http://blog.csdn.net/ironyoung/article/details/49045933
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int s = primes.size();
        vector<int> res(n, INT_MAX), pos(s, 0);
        res[0] = 1;
        for (int i=1; i<n; i++) {
            for (int j=0; j<s; j++) {
                res[i] = (res[i]<res[pos[j]]*primes[j])?res[i]:(res[pos[j]]*primes[j]);
            }
            for (int k=0; k<s; k++) {
                if (res[i]==res[pos[k]]*primes[k]) pos[k]++;
            }
        }
        return res.back();
    }
};