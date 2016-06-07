// 311. Sparse Matrix Multiplication

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res(A.size(), vector<int> (B[0].size(), 0));
        for (int i = 0; i < A.size(); i++) {
            for (int k = 0; k < A[0].size(); k++) {
                if (A[i][k] != 0) {
                    for (int j = 0; j < B[0].size(); j++) {
                        if (B[k][j] != 0) {
                            res[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
        return res;
    }
};


class Solution {
public: 
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res(A.size(), vector<int> (B[0].size(), 0));
        vector<vector<pair<int, int>>> m(A.size(), vector<pair<int, int>> ());
        for (int i = 0; i < A.size(); i++) {
            for (int k = 0; k < A[0].size(); k++) {
                if (A[i][k] != 0) {
                    m[i].push_back({k, A[i][k]});
                }
            }
        }
        
        for (int i = 0; i < A.size(); i++) {
            for (int k = 0; k < m[i].size(); k++) {
                int col = m[i][k].first;
                int val = m[i][k].second;
                for (int j = 0; j < B[0].size(); j++) {
                    res[i][j] += val * B[col][j];
                }
            }
        }
        return res;
    }
};