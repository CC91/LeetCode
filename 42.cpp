// 42. Trapping Rain Water

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n<3) return 0;
        int res = 0;
        stack<int> s;
        s.push(0);
        for (int i=1; i<n; i++) {
            if (height[i]>height[s.top()]) {
                int y = height[s.top()];
                s.pop();
                while (!s.empty() && height[i]>=height[s.top()]) {
                    res += (height[s.top()]-y)*(i-s.top()-1);
                    y = height[s.top()];
                    s.pop();
                }
                if (!s.empty()) res += (height[i]-y)*(i-s.top()-1);
            }
            s.push(i);
        }
        return res;
    }
};


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n<3) return 0;
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int res = 0;
        for (int i=1; i<n; i++) left[i] = max(left[i-1], height[i-1]);
        for (int i=n-2; i>=0; i--) {
            right[i] = max(right[i+1], height[i+1]);
            int minH = min(left[i], right[i]);
            if (minH>height[i]) res += (minH-height[i]);
        }
        return res;
    }
};