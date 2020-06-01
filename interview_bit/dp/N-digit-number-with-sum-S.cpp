#define mod 1000000007
int helper(vector<vector<int>> &dp,int A,int B)
{
    if(A<=0)
    {
        return 0;
    }
    if(A==1)
    {
        if(B>=0 and B<10)
        {
            return 1;
        }
        return 0;
    }
    if(dp[A][B]!=-1)
    {
        return dp[A][B];
    }
    
    long ans = 0;
    for(int i=0;i<10;i++)
    {
        ans = (ans + helper(dp,A-1,B-i))%mod;
    }
    cout<<A<<" "<<B<<" "<<ans<<endl;
    return dp[A][B]=ans;
}
int Solution::solve(int A, int B) {
    
    // cout<<A<<" "<<B<<endl;
        if(A<=0)
    {
        return 0;
    }
    if(A==1)
    {
        if(B>=0 and B<10)
        {
            return 1;
        }
        return 0;
    }
    
    long ans = 0;
    vector<vector<int>> dp(A+1,vector<int>(B+1,-1));
    for(int i=1;i<10;i++)
    {
        long a2 = helper(dp,A-1,B-i);
        cout<<"A2 "<<a2<<endl;
        ans = (ans + helper(dp,A-1,B-i))%mod;
    }
    return ans;
}
