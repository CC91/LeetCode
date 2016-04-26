// 223. Rectangle Area

class Solution {
public: // check if there is overlap or not
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int overlap = 0;
        if (min(D,H)>=max(B, F) && min(C, G)>=max(A, E)) overlap = (min(D, H)-max(B, F))*(min(C, G)-max(A, E));
        return (C-A)*(D-B)+(G-E)*(H-F)-overlap;
    }
};