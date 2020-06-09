#define INF INT_MIN
int dp[1000][1000];
int helper(vector<vector<int>> &A,int i,int j)
{
    int m = A.size();
    int n = A[0].size();
    
    if(i>=m or j>=n)
    {
        return INF;
    }
    if(i==m-1 and j==n-1)
    {
        if(A[i][j]>=0)
        {
            return 1;
        }
        else
            return abs(A[i][j])+1;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int right = helper(A,i,j+1);
    int down = helper(A,i+1,j);
    
    int minPointsOnExit = min(right,down);
    
    int ans = max(minPointsOnExit-A[i][j],1);
    dp[i][j]=ans;
    return ans;
    
}
int helper2(vector<vector<int>> points)
{
    int R = points.size();
    int C = points[0].size();
    int dp[R][C]; 
    int m = R, n = C; 
  
    // Base case 
    dp[m-1][n-1] = points[m-1][n-1] > 0? 1: 
                   abs(points[m-1][n-1]) + 1; 
  
    // Fill last row and last column as base to fill 
    // entire table 
    for (int i = m-2; i >= 0; i--) 
         dp[i][n-1] = max(dp[i+1][n-1] - points[i][n-1], 1); 
    for (int j = n-2; j >= 0; j--) 
         dp[m-1][j] = max(dp[m-1][j+1] - points[m-1][j], 1); 
  
    // fill the table in bottom-up fashion 
    for (int i=m-2; i>=0; i--) 
    { 
        for (int j=n-2; j>=0; j--) 
        { 
            int min_points_on_exit = min(dp[i+1][j], dp[i][j+1]); 
            dp[i][j] = max(min_points_on_exit - points[i][j], 1); 
        } 
     } 
  
     return dp[0][0]; 
}
int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    memset(dp,-1,sizeof(dp));
    return helper2(A,0,0);
}
