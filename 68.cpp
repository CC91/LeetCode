// 68. Text Justification

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int start = 0, end = -1, totLen = 0, i = 0;
        bool isLast = false;
        vector<string> res;
        while (i<words.size()) {
            if (words[i].size()>maxWidth) return res;
            int curL = totLen + (end-start+1) +words[i].size(); // length of current line, (end-start+1) is space numbers
            if (curL<=maxWidth) {
                end = i;
                totLen += words[i].size();
                i++;
            } else {
                string line = createLine(words, maxWidth, start, end, totLen, false);
                res.push_back(line);
                start = i;
                end = i-1;
                totLen = 0;
            }
        }
        string lastLine = createLine(words, maxWidth, start, end, totLen, true);
        res.push_back(lastLine);
        return res;
    }
    
    string createLine(vector<string>& words, int maxWidth, int start, int end, int totLen, bool isLast) {
        string res;
        if (end>=words.size()) return res;
        res.append(words[start]);
        int n = end-start+1; // # of words 
        if (n==1||isLast) { // one word or last line
            for (int i=start+1; i<=end; i++) res.append(' '+words[i]);
            int j = maxWidth-totLen-(n-1); // # of space
            res.append(j, ' ');
            return res;
        }
        
        int k = (maxWidth-totLen)/(n-1), m = (maxWidth-totLen)%(n-1);
        for (int i=start+1; i<=end; i++) { //regular case: fully justified
            int nspace = i-start<=m?k+1:k;
            res.append(nspace, ' ');
            res.append(words[i]);
        }
        return res;
    }
};