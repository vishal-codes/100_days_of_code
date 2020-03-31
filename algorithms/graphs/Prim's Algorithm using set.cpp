
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

            if(visited[g[u][i].first]==false and g[u][i].second<weights[g[u][i].first])
            {
                if(weights[g[u][i].first]!=INF)
                s.erase({weights[g[u][i].first],g[u][i].first}); 
                weights[g[u][i].first]=g[u][i].second;
                parent[g[u][i].first]=u;
                s.insert({weights[g[u][i].first],g[u][i].first});

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



