class Solution {
public:
    void dfs(vector<vector<char>> & board,vector<vector<bool>> &visited,int x,int y)
    {
        int m = board.size();
        int n = board[0].size();
        visited[x][y]=true;
        
        if(x+1<m and (visited[x+1][y]==false and board[x+1][y]=='O'))
        {
            dfs(board,visited,x+1,y);
        }
        
        if(x-1>=0 and (visited[x-1][y]==false and board[x-1][y]=='O'))
        {
            dfs(board,visited,x-1,y);
        }
        
        if(y+1<n and (visited[x][y+1]==false and board[x][y+1]=='O'))
        {
            dfs(board,visited,x,y+1);
        }
        
        if(y-1>=0 and (visited[x][y-1]==false and board[x][y-1]=='O'))
        {
            dfs(board,visited,x,y-1);
        }
        
        
    }
    void solve(vector<vector<char>>& board) {
     
        int m = board.size();
        if(m<=0)
        {
            return;
        }
        int n = board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 cout<<visited[i][j]<<" ";
//                 // if(visited[i][j]==false)
//                     // board[i][j]='X';
                    
//             }
//             cout<<endl;
//         }
        
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O' and visited[i][0]==false)
            dfs(board,visited,i,0);
            
             if(board[i][n-1]=='O' and visited[i][n-1]==false)
            dfs(board,visited,i,n-1);
        }
        
        for(int i=0;i<n;i++)
        {
            if(board[0][i]=='O' and visited[0][i]==false)
            dfs(board,visited,0,i);
            
             if(board[m-1][i]=='O' and visited[m-1][i]==false)
            dfs(board,visited,m-1,i);
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                // cout<<visited[i][j]<<" ";
                if(visited[i][j]==false)
                    board[i][j]='X';
                    
            }
            // cout<<endl;
        }
    }
};