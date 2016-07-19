// 74. Search a 2D Matrix

class Solution {
public: // binary search, O(logmn) time 
// m*n matrix convert to an array: matrix[x][y]=>a[x*n+y], an array convert to m*n matrix=>a[x]: matrix[x/n][x%n];
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m*n-1;
        while (left<=right) {
            int mid = left+(right-left)/2;
            if (matrix[mid/n][mid%n]==target) return true;
            else if (matrix[mid/n][mid%n]>target) right = mid-1;
            else left = mid+1;
        }
        return false;
    }
};


class Solution {
public: // start searching from left bottom
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int row = m-1, col = 0;
        while (row>=0 && col<n) {
            if (matrix[row][col]==target) return true;
            else if (matrix[row][col]>target) row--;
            else col++;
        }
        return false;
    }
};