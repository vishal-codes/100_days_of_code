class Solution {
public:
    bool dfs(vector<int> g[],int color[],int s,int c)
    {
        if(color[s]!=-1 and color[s]!=c)
        {
            return false;
        }
        color[s]=c;
        for(int i=0;i<g[s].size();i++)
        {
            if(color[g[s][i]]!=-1 and color[g[s][i]]==c)
            {
                return false;
            }
            if(color[g[s][i]]==-1 and dfs(g,color,g[s][i],c^1)==false)
            {
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int N, vector<vector<int>>& d) {
        
        vector<int> graph[N+1];
        int color[N+1];
        
        memset(color,-1,sizeof(color));
        
        for(int i=0;i<d.size();i++)
        {
            graph[d[i][0]].push_back(d[i][1]);
            graph[d[i][1]].push_back(d[i][0]);

        }
        
        for(int i=1;i<=N;i++)
        {
            if(color[i]==-1)
            {
                if(dfs(graph,color,i,0)==false)
                    return false;
            }
        }
        return true;
    }
};