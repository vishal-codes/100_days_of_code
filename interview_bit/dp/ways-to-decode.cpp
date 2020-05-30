int helper(string A,int dp[],int n)
{
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    if(n==0 )
    {
        return dp[n]=1;
    }
    if(n==1)
    {
        return dp[n] = A[0]=='0' ? 0 : 1;
    }
    int a = stoi(A.substr(n-1,1));
    
    int ans = 0;
    if(a>=1)
     ans = helper(A,dp,n-1);
    int c = stoi(A.substr(n-2,2));
    if(c>=10 and c<=26)
    {
        ans += helper(A,dp,n-2);
    }
    return dp[n]=ans;
}
int Solution::numDecodings(string A) {
    
    int n = A.size();
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
    return helper(A,dp,n);
}
