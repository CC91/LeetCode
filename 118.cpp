// 118. Pascal's Triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i=0; i<numRows; i++) {
            vector<int> tmp;
            for (int j=0; j<=i; j++) {
                if (j==0 ||j==i) tmp.push_back(1);
                else tmp.push_back(res[i-1][j-1]+res[i-1][j]);
            }
            res.push_back(tmp);
        }
        return res;
    }
};


class Solution {
public: // http://www.geeksforgeeks.org/pascal-triangle/
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i=0; i<numRows; i++) {
            vector<int> tmp;
            for (int j=0; j<=i; j++) {
                if (j==0 ||j==i) tmp.push_back(1);
                else tmp.push_back(tmp[j-1]*(i+1-j)/j);
            }
            res.push_back(tmp);
        }
        return res;
    }
};