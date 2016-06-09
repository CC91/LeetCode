// 296. Best Meeting Point

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        
        int res = 0;
        vector<int> rows;
        vector<int> cols;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        
        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());
    
        int i = 0;
        int j = rows.size() - 1;
        while (i < j) {
            res += rows[j] - rows[i] + cols[j--] - cols[i++];
        }
        
        return res;
    }
};