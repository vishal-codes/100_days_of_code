/*
	Topological Sort is very simple using dfs , store all the 
	visted vertex from adjacent node's then store the current vertex.
	Then simply reverse the vector.
*/

// The Graph structure is as folows

/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*/
void TopologicalSort(vector<int> adj[],int source,vector<bool>& visited,vector<int>& ans)
{
    visited[source]=true;
    for(int i=0;i<adj[source].size();i++)
    {
        int d = adj[source][i];
        if(visited[d]==false)
        {
            TopologicalSort(adj,d,visited,ans);
        }
    
    }
    ans.push_back(source);
}
vector<int> topoSort(int V, vector<int> adj[]) {
    // Your code here
    vector<int> ans;
    vector<bool> visited(V,false);
    
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        {
            TopologicalSort(adj,i,visited,ans);
        }
    }
    

    reverse(ans.begin(),ans.end());
    
    
    return ans;
    
}
/*
	Time Complexity : O(V+E)
	Space Complexity : O(V)
*/