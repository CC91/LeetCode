// 255. Verify Preorder Sequence in Binary Search Tree

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int minNode = INT_MIN;
        stack<int> s;
        for (int a : preorder) {
            if (a < minNode) {
                return false;
            }
            while (!s.empty() && a > s.top()) {
                minNode = s.top();
                s.pop();
            }
            s.push(a);
        }
        return true;
    }
};


class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int minNode = INT_MIN;
        int i = -1;
        for (int a : preorder) {
            if (a < minNode) {
                return false;
            }
            while (i >= 0 && a > preorder[i]) {
                minNode = preorder[i--];
            }
            preorder[++i] = a;
        }
        return true;
    }
};