int lcs(string A,string B)
{
    int m=A.size();
    int n=B.size();
    int dp[m+1][n+1];

    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 or j==0){
                dp[i][j]=0;
                continue;
            }
            if(A[i-1]==B[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}
int Solution::isInterleave(string A, string B, string C) {
    
        int m = A.size();
    int n = B.size();
    
    if(m+n<C.size()or C.size()<m+n)
    {
        return 0;
    }
    int a = lcs(A,C);
    int b = lcs(B,C);
//     cout<<a<<" "<<b<<endl;
    if(a==m and b==n)
    {
        return 1;
    }
    return 0;
}
