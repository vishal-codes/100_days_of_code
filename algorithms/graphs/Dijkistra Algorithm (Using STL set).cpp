/* Dijskistra Algorithm is single source shorted path algorithm .
  It works for both directed and undirected graph , given that weight of the graph is positive.
  In case of all the weights is to be 1 , then dijkistra algorithm is equivalent to the bfs
*/

#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
void dijkistra(vector<pair<int,int>> g[],int n,int source)
{
    /* Distance vector stores the shortest distance of i from source */

    // Initialise the distance array with INF
    vector<int> distance(n,INF);

    /* first element is distance and second member is the vertex in the set*/
    
    set<pair<int,int>> s;
    
    distance[source]=0;
    
    s.insert({distance[source],source});

    while(!s.empty())
    {
        /* Choose the vertex with the minimum distance*/
        auto it = s.begin();
        int u = (*it).second;
        /* Delete the vertex from the set*/
        s.erase(it);
        for(int i=0;i<g[u].size();i++)
        {
            int v = g[u][i].first;
            int d = g[u][i].second; // value of edge u-v
                    
            if(distance[v]>distance[u]+d)
            {
                // 1) If distance is infinity it means it has not in the set
                // 2) If present in the set , delete the previous distance 
                // 3) Update the new distance
                if(distance[v]!=INF)
                s.erase({distance[v],v});
                

                // update the distance
                distance[v]=distance[u]+d;
                
                // insert the new distance
                s.insert({distance[v],v});
            }
        }
    }

    for(int i=0;i<n;i++)
        cout<<i<<" "<<distance[i]<<endl;
}
int main()
{
    vector<pair<int,int>> g[200005];
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int x,y,w;

        cin>>x>>y>>w;

        g[x].push_back({y,w});
        g[y].push_back({x,w});

    }
    dijkistra(g,n,0);
    return 0;
}
/*
Time Complexity : O(Elog(V))
Space Complexity : O(E+V)
*/