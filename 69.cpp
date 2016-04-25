// 69. Sqrt(x) 

class Solution {
public: // // newton's method https://en.wikipedia.org/wiki/Integer_square_root
    int mySqrt(int x) {
        if (x<=1) return x;
        double x0 = 1, x1;
        while (1) {
            x1 = (x0+x/x0)/2;
            if (abs(x1-x0)<1) return x1;
            x0 = x1;
        }
    }
};


class Solution {
public: // binary search
    int mySqrt(int x) {
        if (x<=1) return x;
        int i = 0, j = x;
        while (i<=j) {
            int mid = i+(j-i)/2;
            if (x/mid==mid) return mid;
            else if (x/mid>mid) i = mid+1;
            else j = mid-1;
        }
        return j;
    }
};