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
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
            return NULL;

        unordered_map<int, UndirectedGraphNode *> cloned;
        unordered_map<int, bool> visited; // For BFS
        queue<UndirectedGraphNode *> q;

        q.push(node);
        while (!q.empty()) {
            UndirectedGraphNode *cur = q.front();
            q.pop();
            if (!visited[cur->label]) {
                visited[cur->label] = true;
                
                // Create copy
                UndirectedGraphNode *c = cloned[cur->label];
                if (!c) {
                    c = new UndirectedGraphNode(cur->label);
                    cloned[cur->label] = c;
                }
                
                // Make connections for the copy
                for (int i=0; i<cur->neighbors.size(); ++i) {
                    // Insert the copy of its neighbor
                    UndirectedGraphNode *n = cloned[cur->neighbors[i]->label];
                    if (!n) {
                        n = new UndirectedGraphNode(cur->neighbors[i]->label);
                        cloned[cur->neighbors[i]->label] = n;
                    }
                    c->neighbors.push_back(n);
                    
                    q.push(cur->neighbors[i]);
                }
            }
            
        }
        
        return cloned[node->label];
    }
};