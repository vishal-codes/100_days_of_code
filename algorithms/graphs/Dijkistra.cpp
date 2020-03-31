#include <vector>
#include<iostream>
#include<climits>
using namespace std;

int findMinVertex(vector<int>& weights,vector<bool>& visited, int n){

    int minVertex = -1;
    for(int i = 0; i < n; i++){
        if(!visited[i] && (minVertex == - 1 || weights[i] < weights[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;=
}

!=-1)
     {
void Dijkistra(int** g, int n){

    //
    vector<int> distance(n);
    vector<bool> visited(n);

    for(int i=0;i<n;i++)
    {
        distance[i]=INT_MAX;
        visited[i]=false;
    } 

     int source = 0;
     distance[source]=0;

     int cv = 0;
     while(cv
        visited[cv]=true;
        for(int i=0;i<n;i++)
        {
            if(g[cv][i]!=0 and visited[i]==false)
            {
                int dis =  distance[cv] + g[cv][i];
                if(dis<distance[i])
                {
                    distance[i]=dis;
                }
            }
        }
        cv = findMinVertex(distance,visited,n);
     }
     for(int i=0;i<n;i++)
     {
        cout<<" "<<i<<" "<<distance[i]<<endl;
     }
}

int main() {
    int n;
    int e;
    cin >> n >> e;
    int** edges = new int*[n];
    for (int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++) {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++) {
        int f, s, weight;
        cin >> f >> s >> weight;
        edges[f][s] = weight;
        edges[s][f] = weight;
    }
  //  cout << endl;
    Dijkistra(edges, n);

    for (int i = 0; i < n; i++) {
        delete [] edges[i];
    }
    delete [] edges;
}



