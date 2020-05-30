class Solution {
public:
    bool dfs(vector<int> graph[],char color[],int s)
    {
        
        color[s]='g';
        for(int i=0;i<graph[s].size();i++)
        {
            
            int d = graph[s][i];
            if(color[d]=='g')
            {
                return false;
            }
            if(color[d]=='w')
            {
                if(dfs(graph,color,d)==false)
                {
                    return false;
                }
            }
        }
        color[s]='b';
        return true;   
    }
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        int n = numCourses;
        char color[n];
        fill(color,color+n,'w');
        vector<int> graph[n];
        
        for(int i=0;i<p.size();i++)
        {
            graph[p[i][1]].push_back(p[i][0]);
        }
        
        for(int i=0;i<n;i++)
        {
         if(color[i]=='w' and !dfs(graph,color,i))
         {
             return false;
         }
        }
        return true;
        
    }
};