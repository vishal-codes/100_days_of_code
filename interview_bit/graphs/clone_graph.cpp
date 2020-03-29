/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
void dfs(UndirectedGraphNode* node,unordered_map<UndirectedGraphNode*,UndirectedGraphNode*>& v)
{
    UndirectedGraphNode* n = new UndirectedGraphNode(node->label);    
    v[node]=n;
     for(int i=0;i<node->neighbors.size();i++)
        {
            if(v.find(node->neighbors[i])==v.end())
            {
                dfs(node->neighbors[i],v);
            }
            n->neighbors.push_back(v[node->neighbors[i]]);
        }
}
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {

        unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> v;
        dfs(node,v);
        return v[node];
}
