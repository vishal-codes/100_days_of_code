#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
void dijkistra(vector<pair<int,int>> g[],int n,int source)
{
    // Initialise the distance array
    vector<int> distance(n);

    // Intialisze the distance with infinity
    fill(distance.begin(),distance.end(),INF);

    set<pair<int,int>> s;
    distance[source]=0;
    s.insert({distance[source],source});

    while(!s.empty())
    {
        auto it = s.begin();
        int u = (*it).second;
        s.erase(it);
        for(int i=0;i<g[u].size();i++)
        {
            if(distance[g[u][i].first]>distance[u]+g[u][i].second)
            {
                if(distance[g[u][i].first]!=INF)
                s.erase({distance[g[u][i].first],g[u][i].first});
                distance[g[u][i].first]=distance[u]+g[u][i].second;
                s.insert({distance[g[u][i].first],g[u][i].first});
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