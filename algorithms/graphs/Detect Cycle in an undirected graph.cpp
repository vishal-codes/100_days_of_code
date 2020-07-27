#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back

/* Cycle Detection in undirected graph using dfs*/
/* Cycle is present in undirected graph is there is an edge from unvisted vertex 
to a visited vertex and the visited vertex is not the parent of the unvisited 
vertex during dfs traversal*/

/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/
bool dfs(int source,vector<int> g[],vector<bool>& visited,int parent)
{
       visited[source]=true;
       
       // trvaerse for adjacent vertex
       for(int i=0;i<g[source].size();i++)
       {
           int dest = g[source][i];
           
           // If unvisited do a dfs and check for cycle
           if(visited[dest]==false)
           {
               
                if(dfs(dest,g,visited,source))
                return true;
           }
            else
            // If it is not parent of current/source vertex return true
            {
                if(dest!=parent)
                    return true;
            }
       }
       // graph does not contain any cycle
       return false;
}
bool isCyclic(vector<int> g[], int V)
{
   // Your code here
   vector<bool> visited(V,false);
   
   for(int i=0;i<V;i++)
   {
       if(visited[i]==false)
       {
           if(dfs(i,g,visited,-1))
            return true;
       }
   }
   return false;
}
/* Time Complexity  : O(V+E)
/* Space Complexity : O(V)