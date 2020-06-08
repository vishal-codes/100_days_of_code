static int dp[501][501];
int helper(vector<int> &A,int i,int j)
{
    if(i>j)
    {
        return 0;
    }
    if(i==j)
    {
        return A[i];
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int ans = max(A[i]+min(helper(A,i+2,j),helper(A,i+1,j-1)),A[j]+min(helper(A,i+1,j-1),helper(A,i,j-2)));
    dp[i][j]=ans;
    return ans;
    
}
int Solution::maxcoin(vector<int> &A) {
    memset(dp,-1,sizeof(dp));
    return helper(A,0,A.size()-1);
}
