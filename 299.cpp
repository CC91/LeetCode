// 299. Bulls and Cows

class Solution {
public:
    string getHint(string secret, string guess) {
        int m[256] = {0}, b = 0, c = 0;
        for (int i=0; i<secret.size(); i++) {
            if (secret[i]==guess[i]) b++;
            else {
                if (m[secret[i]]++<0) c++; // the char appeared in the guess before
                if (m[guess[i]]-->0) c++; // the char appeared in the secret before
            }
        }
        return to_string(b)+"A"+to_string(c)+"B";
    }
};