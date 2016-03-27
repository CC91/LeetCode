// 42. Trapping Rain Water

class Solution {
public: // use a stack to track the decreasing and increasing sink with their indices
    int trap(vector<int>& height) {
        int n = height.size(), res = 0;
        if (n<3) return res;
        stack<int> s;
        s.push(0);
        for (int i=1; i<n; i++) {
            if (height[i]>height[s.top()]) {
                int bottom = height[s.top()];
                s.pop();
                while (!s.empty() && height[i]>=height[s.top()]) {
                    res += (height[s.top()]-bottom)*(i-s.top()-1);
                    bottom = height[s.top()];
                    s.pop();
                }
                if (!s.empty() && height[i]<height[s.top()]) res += (height[i]-bottom)*(i-s.top()-1); // corner case
            }
            s.push(i);
        }
        return res;
    }
};


class Solution {
public: // 2 pointers represent the left height and right height of any position
    int trap(vector<int>& height) {
        int n = height.size(), res = 0;
        if (n<3) return res;
        vector<int> l(n, 0), r(n, 0);
        for (int i=1; i<n; i++) l[i] = max(l[i-1], height[i-1]);
        for (int i=n-2; i>=0; i--) { // right part must start from right
            r[i] = max(r[i+1], height[i+1]);
            int minHeight = min(l[i], r[i]);
            if (minHeight>height[i]) res += minHeight-height[i];
        }
        return res;
    }
};


class Solution {
public: // find hightest bar, compute area from left for 1st half and from right for the 2nd half.
    int trap(vector<int>& height) {
        int n = height.size(), res = 0;
        if (n<3) return res;
        int m = 0;
        for (int i=1; i<n; i++) {
            if (height[i]>height[m]) m = i;
        }
        for (int i=0, top=0; i<m; i++) {
            if (height[i]>top) top = height[i];
            else res += top-height[i];
        }
        for (int i=n-1, top=0; i>m; i--) {
            if (height[i]>top) top = height[i];
            else res += top-height[i];
        }
        return res;
    }
};