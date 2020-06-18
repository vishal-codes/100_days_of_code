class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        vector<vector<int>> g(n,vector<int>(n,0));
        for(int i=0;i<flights.size();i++)
        {
            g[flights[i][0]][flights[i][1]] =flights[i][2];
        }
        set<pair<int,pair<int,int>>> s;
        set<pair<int,int>> visited;
        s.insert({0,{src,1}});
        visited.insert({src,1});
        while(!s.empty())
        {
             pair<int,pair<int,int>> p = *(s.begin());
             s.erase(s.begin());
             int u = p.second.first;
             int price = p.first;
             int k = p.second.second;
            // cout<<u<<" "<<k<<endl;
             visited.insert({u,k});
            if(k<=K+2)
            {
               
                if(u==dst)
                {
                    return price;
                }
                for(int i=0;i<g[u].size();i++)
                {
                    if(g[u][i]!=0 and (visited.find({i,k+1})==visited.end()))
                    {
                        s.insert({price+g[u][i],{i,k+1}});
                    }
                }
            }
        }
        return -1;
    }
};