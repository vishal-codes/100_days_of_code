bool isValid(vector<vector<char>>& A,int x,int y,vector<vector<bool>> &visited)
{
    int m = A.size();
    int n = A[0].size();
    if((x<m and x>=0) and (y<n and y>=0))
    {
        if(!visited[x][y])
        {
            return A[x][y]=='O';
        }
    }
    return false;
}
void bfs(vector<vector<char>>&A,int x,int y,vector<vector<bool>> &visited)
{
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y]=true;
    while(!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();
        x=p.first;
        y=p.second;
        visited[x][y]=true;
        if(isValid(A,x+1,y,visited)){q.push({x+1,y});visited[x+1][y]=true;}
        if(isValid(A,x,y+1,visited)){q.push({x,y+1});visited[x][y+1]=true;}
        if(isValid(A,x,y-1,visited)){q.push({x,y-1});visited[x][y-1]=true;}
        if(isValid(A,x-1,y,visited)){q.push({x-1,y});visited[x-1][y]=true;}
    }
    
}
void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<bool>> visited;
    int m = A.size();
    int n = A[0].size();
    
    for(int i=0;i<m;i++)
    {
        vector<bool> v;
        for(int j=0;j<n;j++)
        {
            v.push_back(false);
        }
        visited.push_back(v);
    }
    for(int i=0;i<m;i++)
    {
        if(A[i][0]=='O' and visited[i][0]==false)
        {
            bfs(A,i,0,visited);
        }
        if(A[i][n-1]=='O' and visited[i][n-1]==false)
        {
            bfs(A,i,n-1,visited);
        }
        
    }
    for(int i=0;i<n;i++)
    {
        if(A[0][i]=='O' and visited[0][i]==false)
        {
            bfs(A,0,i,visited);
        }
        if(A[m-1][i]=='O' and visited[m-1][i]==false)
        {
            bfs(A,m-1,i,visited);
        }
        
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(visited[i][j]==false)
            {
                A[i][j]='X';
            }
        }
    }
}
