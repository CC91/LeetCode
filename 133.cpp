// 133. Clone Graph

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) {
            return node;
        }
        if (!m.count(node)) {
            m[node] = new UndirectedGraphNode(node -> label);
            for (auto n :node -> neighbors) {
                m[node] -> neighbors.push_back(cloneGraph(n));
            }
        }
        return m[node];
    }
};