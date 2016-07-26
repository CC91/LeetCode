// 364. Nested List Weight Sum II

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int res = 0;
        vector<int> tmp;
        for (auto a : nestedList) {
            helper(a, 0, tmp);
        }
        for (int i = 0; i < tmp.size(); i++) {
            res += tmp[i] * (tmp.size() - i);
        }
        return res;
    }
    
    void helper(NestedInteger n, int depth, vector<int> &res) {
        if (depth >= res.size()) {
            res.resize(depth + 1);
        }
        if (n.isInteger()) {
            res[depth] += n.getInteger();
        } else {
            for (auto a : n.getList()) {
                helper(a, depth + 1, res);
            }
        }
    }
};


class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int weighted = 0;
        int unweighted = 0;
        while (!nestedList.empty()) {
            vector<NestedInteger> nextLevel;
            for (auto a : nestedList) {
                if (a.isInteger()) {
                    unweighted += a.getInteger();
                } else {
                    nextLevel.insert(nextLevel.end(), a.getList().begin(), 
                    		a.getList().end());
                }
            }
            weighted += unweighted;
            nestedList = nextLevel;
        }
        return weighted;
    }
};