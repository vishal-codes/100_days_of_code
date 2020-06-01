int Solution::canJump(vector<int> &A) {
    
    int n = A.size();
    if(n<=1)
    {
        return 1;
    }
    int dp[n];
    dp[n-1]=1;
    for(int j=n-1;j>=0;j--)
    {
        dp[j]=0;
        for(int i=0;i<=A[j];i++)
        {
            if(j+i<n)
            {
                if(dp[j+i]==1)
                {
                    dp[j]=1;
                    break;
                }
            }
            else
            {
                dp[j]=1;
                break;
            }
        }
    }
    return dp[0];
}
