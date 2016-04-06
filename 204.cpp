// 204. Count Primes

class Solution {
public: // https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
    int countPrimes(int n) {
        if (n<=2) return 0;
        int res = 1;
        int upper = sqrt(n);
        vector<bool> isPrime(n, true);
        for (int i=3; i<n; i+=2) {
            if (isPrime[i]) {
                res++;
                if (i>upper) continue;
                for (int j=i*i; j<n; j+=i) isPrime[j] = false;
            }
        }
        return res;
    }
};