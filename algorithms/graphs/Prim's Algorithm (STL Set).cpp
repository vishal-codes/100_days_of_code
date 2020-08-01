/* Prim's Algorithm finds the minimum spannig tree f a graph. The graph must be connected.
The main idea behind the Prim's algorihtm is that , Prim's Algorithm selects the minimum weight connected
edge at a time , untill n-1 edges are found */
#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX


void prims(vector<pair<int,int>> g[], int n){

    int* parent = new int[n];
    int* weights = new int[n];
    bool* visited = new bool[n];    


    for(int i = 0; i < n; i++){
        
        visited[i]=false;
        weights[i] = INT_MAX;
    }
    parent[0] = -1;
    weights[0] = 0;
    set<pair<int,int>> s;
    s.insert({weights[0],0});
    

    while(s.empty()==false){
        // Find Min Vertex
        // int minVertex = findMinVertex(weights, visited, n);
        auto it = s.begin();
        s.erase(it);
        int u = (*it).second;
        visited[u]=true;
        // Explore un visted neighbours
        for(int i = 0; i < g[u].size(); i++){

            int v = g[u][i].first;
            int d = g[u][i].second; // distance between u and v
            if(visited[v]==false and d<weights[v])
            {
                // delete the previous entry from the set
                if(weights[v]!=INF)
                s.erase({weights[v],v}); 

                // Update the weights
                weights[v]=g[u][i].second;

                // update the parents
                parent[v]=u;

                // insert the new weight into the set
                s.insert({weights[v],v});

            }
        }
    }

    for(int i = 1; i < n; i++){
        if(parent[i] < i){
            cout << parent[i] << " "<< i << " " << weights[i] << endl;
        }else{
            cout << i << " " << parent[i] << " " << weights[i] << endl;
        }
    }
}

int main() {

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
    prims(g,n);
    return 0;
}

/*
Time Complexity : O(Elog(V))
Space Complexity : O(E+V)
*/

