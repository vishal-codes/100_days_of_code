// If in a DFS search traversal there is a back edge then there is cycle
// present in the undirected graph. The number of back edge is equal to the
// number of cycles present in the graph

// Back Edge : An edge from a node to itself or to it's ancestors in tree
// made using DFS traversal

// Implementing Algorithm


bool dfs(vector<vector<int>> &graph,int source,vector<bool> &visited,vector<bool> &recursionStack)
{

	// Mark current node as true
	visited[source]=true;
	recursionStack[source]=true;

	// Traverse to the adjacent nodes if an edge to a node in
	// recursion stack return true

	for(int i=0;i<graph[source].size();i++)
	{
		int dest = graph[source][i];

		if(visited[dest]==false and dfs(graph,dest,visited,recursionStack)==true)
		{
			return true;
		}
		else if(recursionStack[dest]==true)
		{
			return true;
		}
	}

	// remove node from recursion stack
	recursionStack[source]=false;
	return false;


}




// If cycle is present this funcion returns true otherwise false
bool isCyclePresent(vector<vector<int>> &graph,int Vertices)
{

	// The graph is is adjacency list representation
	// Intialising visiting and recursion Stack to false
	vector<bool> visited(Vertices,false);
	vector<bool> recursionStack(Vertices,false);

	for(int i=0;i<Vertices;i++)
	{
		if(visited[i]==false and dfs(graph,i,visited,recursionStack))
		{
			return true;
		}
	}
	return false;
}

/*

Complexity Analysis:
	Time Complexity: O(V+E).
		Time Complexity of this method is same as time complexity of DFS traversal which is O(V+E).
	Space Complexity: O(V).
		To store the visited and recursion stack O(V) space is needed.
*/