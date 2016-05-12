// 68. Text Justification 


class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        if (words.empty()) return res;
        int i = 0;
        while (i < words.size()) {
            int start = i;
            int len = 0;
            while (i < words.size() && len + words[i].size() <= maxWidth) {
                len += words[i].size() + 1;
                i++;
            }
            int end = i - 1;
            int intervalCount = end - start;
            int avgSp = 0;
            int leftSp = 0;
            if (intervalCount > 0) {
                avgSp = (maxWidth - len + intervalCount + 1) / intervalCount;
                leftSp = (maxWidth - len + intervalCount + 1) % intervalCount;
            }
            string line;
            for (int j = start; j < end; j++) {
                line += words[j];
                if (i == words.size()) {
                    line.append(1, ' ');
                } else {
                    line.append(avgSp, ' ');
                    if (leftSp > 0) {
                        line.append(1, ' ');
                        leftSp--;
                    }
                }
            }
            line += words[end];
            if (line.size() < maxWidth) {
                line.append(maxWidth-line.size(), ' ');
            }
            res.push_back(line);
        }
        return res;
    }
};