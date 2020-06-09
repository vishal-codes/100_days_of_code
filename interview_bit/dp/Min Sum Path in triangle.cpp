// simple recursion ane memoization
int dp[1001][1001];
int helper(vector<vector<int>> &A,int i,int j)
{
    int m = A.size();
    int n = A[0].size();
    
    
    if(i==m-1)
    {
        return A[i][j];
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int minPath = min(helper(A,i+1,j),helper(A,i+1,j+1));
    int ans = minPath + A[i][j];
    dp[i][j]=ans;
    return ans;
}

int Solution::minimumTotal(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int m = A.size();
    if(m<=0)
    {
        return 0;
    }
    memset(dp,-1,sizeof(dp));
    return helper(A,0,0);
}
// Bottom Up O(n) spcae
int helper2(vector<vector<int>> A)
{
    int m = A.size();
    int n = A[m-1].size();

    int dp[n];
    i
    if(m==1)
    {
        return A[0][0];
    }
   
    for(int i=0;i<n;i++)
        dp[i]=A[m-1][i];

    for(int i=m-2;i>=0;i--)
    {
        for(int j=0;j<A[i].size();j++)
        {
            dp[j]=min(dp[j],dp[j+1])+A[i][j];
        }
        
    }
    return dp[0];

}