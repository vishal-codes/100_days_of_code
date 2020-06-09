int dp[102][102];
int helper(vector<vector<int>> &A,int i,int j)
{
    int m = A.size();
    int n = A[0].size();
    
    if(i>=m or j>=n)
    {
        return 0;
    }
    if(i==m-1 and j==n-1)
    {
        return A[i][j]==0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(A[i][j]==1)
    {
        return 0;
    }
    dp[i][j]=helper(A,i+1,j)+helper(A,i,j+1);
    return dp[i][j];
}
int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int m = A.size();
    if(m<=0)
    {
        return 0;
    }
    memset(dp,-1,sizeof(dp));
    return helper(A,0,0);
}
