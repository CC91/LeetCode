// 84. Largest Rectangle in Histogram

class Solution {
public: // stack, store indices of the histogram
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> s;
        heights.push_back(-1);
        heights.insert(heights.begin(), -1);
        for (int i=0; i<heights.size(); i++) {
            while (!s.empty() && heights[i]<heights[s.top()]) {
                int h = heights[s.top()];
                s.pop();
                res = max(res, (i-s.top()-1)*h); 
            }
            s.push(i);
        }
        return res;
    }
};