#define mod 1000007
int Solution::coinchange2(vector<int> &A, int B) {
    int m=A.size();
    if(m<=0)
    {
        return 0;
    }
    int n = B;
    
    int dp[n+1];
    
    for(int i=0;i<=n;i++)
        dp[i]=0;
    
    dp[0]=1;
    
        
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(A[i-1]<=j)
            {
                dp[j]=(dp[j]+dp[j-A[i-1]])%mod;
            }
            
        }
    }
    return dp[n];
}
