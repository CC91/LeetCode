// 6. ZigZag Conversion

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        string res;
        int zzSize = 2*numRows-2;
        
        for (int i=0; i<numRows; i++) {
            for (int j=i; j<s.size(); j+=zzSize) {
                res.append(1, s[j]);
                if (i!=0 && i!= numRows-1) { 
                    int idx = zzSize-2*i+j;
                    if (idx<s.size()) res.append(1, s[idx]);
                }
            }
        }
        return res;
    }
};

