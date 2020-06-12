class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
       
        // make the graph
        vector<vector<int>> g;
        for(int i=0;i<n;i++)
        {
            vector<int> v;
            g.push_back(v);
        }
        for(int i=0;i<edges.size();i++)
        {
            int x = edges[i][0]-1;
            int y = edges[i][1]-1;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        
        // Go for bfs
        vector<int> visited(n);
        fill(visited.begin(),visited.end(),0);
        // node , time and probabilty
        queue<pair<int,pair<int,double>>> q;
        q.push({0,{t,1}});
        
        
        while(!q.empty())
        {
            
            pair<int,pair<int,double>> p = q.front();
            q.pop();
            
            int node = p.first;
            int time = p.second.first;
            double cp   = p.second.second;
            visited[node]=1;
            if(time<0)
            {
                return 0;
            }
                
            if(node==target-1)
            {
                if(time==0)
                return cp;
                if(time>0)
                {
                    int count = 0;
            for(int i=0;i<g[node].size();i++)
            {
                int u = g[node][i];
                if(visited[u]==0)
                {
                    count++;
                }
            }
                    if(count==0)
                    {
                        return cp;
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
            int count = 0;
            for(int i=0;i<g[node].size();i++)
            {
                int u = g[node][i];
                if(visited[u]==0)
                {
                    count++;
                }
            }
            if(count!=0)
            {
            double prob = cp *((1*1.0)/count);
            // cout<<prob<<endl;
            for(int i=0;i<g[node].size();i++)
            {
                int u = g[node][i];
                if(!visited[u])
                {
                    q.push({u,{time-1,prob}});
                }
            }
            }
        
            
        }
        double ans = (double)0;
        return 0;
    }
};