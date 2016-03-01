// 11. Container With Most Water

class Solution {
public: // 2 pointers
    int maxArea(vector<int>& height) {
        int h = height.size();
        int start = 0, end = h-1, res = 0;
        while (start<end) {
            int area = abs(end-start)*min(height[start], height[end]);
            res = max(area, res);
            if (height[start]<height[end]) start++;
            else if (height[start]>height[end]) end--;
            else { // attention!
                start++;
                end--;
            }
        }
        return res;
    }
};