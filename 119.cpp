// 119. Pascal's Triangle II

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        for (int i=0; i<=rowIndex; i++) {
            res.push_back(1);
            for (int j=i-1; j>0; j--) {
                res[j] += res[j-1]; // calculate reversely
            }
        }
        return res;
    }
};


class Solution {
public: // integer overflow because of multiplication
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.push_back(1);
        int i = 1;
        while (i<=rowIndex) {
            res.push_back(res[i-1]*(rowIndex+1-i)/i);
            i++;
        }
        return res;
    }
};