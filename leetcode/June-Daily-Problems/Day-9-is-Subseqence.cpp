class Solution {
public:
    int lcs(string s,string t)
    {
        int m = s.size();
        int n = t.size();
        
        int dp[m+1][n+1];
        
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 or j==0)
                {
                    dp[i][j]=0;
                }
                else
                {
                    if(s[i-1]==t[j-1])
                    {
                        dp[i][j]=1+dp[i-1][j-1];
                    }
                    else
                        dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[m][n];
    }
    bool isSubsequence(string s, string t) {
        return lcs(s,t)==s.size();
    }
};