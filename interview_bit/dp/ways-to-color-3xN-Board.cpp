#define mod 1000000007
int helper(int dp[4][4][4][123456],int i,int j,int k,int n)
{
	if(n==0)
	{
		return 1;
	}
	if(dp[i][j][k][n]!=-1)
	{
		return dp[i][j][k][n];
	}

	long ans = 0;
	for(int i1=0;i1<4;i1++)
	{
		for(int j1=0;j1<4;j1++)
		{
			for(int k1=0;k1<4;k1++)
			{
				if((i1!=j1 and j1!=k1)and(i1!=i and j1!=j and k1!=k))
				{
					ans = (ans + helper(dp,i1,j1,k1,n-1))%mod;
				}
			}
		}
	}
	
	return dp[i][j][k][n]=ans;


}
int Solution::solve(int A) {
    if(A==0)
    {
        return 0;
    }
    int dp[4][4][4][123456];

	memset(dp,-1,sizeof(dp));

	long ans = 0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			for(int k=0;k<4;k++)
			{
				if(j!=i and k!=j)
				{
					ans = (ans + helper(dp,i,j,k,A-1))%mod;
				}
			}
		}
	}
	return ans;
}
