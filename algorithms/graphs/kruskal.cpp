#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Kruskal's algorithm

// Edge's Class
class edge
{
public:
    int s,d,w;
    edge(int s,int d,int w)
    {
        this->s=s;
        this->d=d;
        this->w=w;
    }
    void print()
    {
        if(s<d)
        cout<<s<<" "<<d<<" "<<w<<endl;
        else
        cout<<d<<" "<<s<<" "<<w<<endl;

    }
};

// Input is the graph's edge
// Output is the edge's in MST
bool compare(const edge &a,const edge &b)
{
    return a.w<b.w;
}
int getParent(vector<int> parent,int s)
{
    while(parent[s]!=s)
    {
        int p = parent[s];
        s=p;
    }
    return s;
}
vector<edge> MST_using_Kruskal(int v,vector<edge> g)
{
    // sort the edges according to weight
    sort(g.begin(),g.end(),compare);

    // add each edges to the MST from the sorted edges only if adding it to 
    // MST does not make any cycles in the MST
    // We can use union-find algorithm to find that if the cycle exist or not
    vector<int> parent(v);
    for(int i=0;i<v;i++) parent[i]=i;

    //MST
    vector<edge> MST;

    int count = 0;
    // add n-1 edges to the MST
    int i=0;
    while(count<v-1)
    {
        //
        int s = g[i].s;
        int d = g[i].d;
        // if both belong different set
        int s1 = getParent(parent,s);
        int d1 = getParent(parent,d);

        if(s1!=d1)
        {
            MST.push_back(g[i]);
            count++;
            // Update the parent pointer
            parent[s1]=parent[d1];
        }
        i++;
    } 
    return MST;
} 
int main() {
    int v,E,tempX,tempY,w;
    cin>>v>>E;
    vector<edge> g;
    for(int i=0;i<E;i++)
    {
        cin>>tempX>>tempY>>w;
        g.push_back(edge(tempX,tempY,w));
    }
    vector<edge> mst = MST_using_Kruskal(v,g);
    for(int i=0;i<mst.size();i++)
    {
        mst[i].print();
    }
    return 0;
}