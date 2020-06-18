//https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
bool helper(int s,vector<int> a[],vector<bool> &v,vector<bool> &r)
{
    v[s]=true;
    r[s]=true;
    
    for(int k=0;k<a[s].size();k++)
    {
        int i = a[s][k];
        if(v[i]==false and helper(i,a,v,r)==true)
        {
            return true;
        }
        else if(r[i]==true)
        {
            return true;
        }
    }
    r[s]=false;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    vector<bool> v(V,false);
    vector<bool> r(V,false);
    
    for(int i=0;i<V;i++){
        if(v[i]==false and helper(i,adj,v,r)==true)
        {
            return true;
        }
    }
    return false;
}