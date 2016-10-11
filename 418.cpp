// 418. Sentence Screen Fitting

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int len = 0;
        for (auto a : sentence) {
            if (a.size() > cols) {
                return 0;
            }
            len += a.size() + 1;
        }
        int n = sentence.size();
        int i = 0;
        int res = 0;
        for (int r = 0; r < rows; r++) {
            int end = cols + 1;
            res += end / len;
            end %= len;
            while (end >= sentence[i].size() + 1) {
                end -= sentence[i++].size() + 1;
                if (i == n) {
                    res++;
                    i = 0;
                }
            }
        } 
        return res;
    }
};