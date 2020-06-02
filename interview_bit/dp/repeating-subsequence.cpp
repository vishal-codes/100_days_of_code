
    int m = A.size();
    int dp[m+1][m+1];
    
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
                continue;
            }
            if(i==j)
            {
                dp[i][j]=0;
                continue;
            }
            if(A[i-1]==A[j-1])
            dp[i][j]=dp[i-1][j-1]+1;
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(dp[i][j]>1)
                return 1;
        }
    }
    return 0;