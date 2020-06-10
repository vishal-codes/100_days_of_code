int helper(vector<vector<int>> &dp,string& A,int i,int B)
{
    int n = A.size();
    if(B==0)
    {
        int w = 0;
        int b = 0;
        for(int j=i;j<n;j++)
        {
            if(A[j]=='W')
                w++;
            else
                b++;
        }
        dp[i][B]=w*b;
        return w*b;
    }
    if(n-i+1==B-1)
    {
        return 0;
    }
    if(dp[i][B]!=-1)
    {
        return dp[i][B];
    }
    int w=0;
    int b=0;
    int j=i;
    int ans=INT_MAX;
    while(n-j>=B)
    {
        if(A[j]=='W')
            w++;
        else
            b++;
        int tempans = w*b+helper(dp,A,j+1,B-1);
        ans = min(ans,tempans);
        j++;
    }
    dp[i][B]=ans;
    return ans;
}
int Solution::arrange(string A, int B) {
    
    if(A.size()<B)
    {
        return -1;
    }
    int n = A.size();
    vector<vector<int>> dp(n+1,vector<int>(B+1,-1));
    return helper(dp,A,0,B-1);
}
