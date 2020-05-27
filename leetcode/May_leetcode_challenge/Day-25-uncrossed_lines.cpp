class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int m = A.size();
        int n = B.size();
        
        if(m==0)
        {
            return 0;
        }
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++)
            dp[i][0]=0;
        for(int j=0;j<=n;j++)
            dp[0][j]=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(A[i-1]==B[j-1])
                {
                    dp[i][j]= max(1+dp[i-1][j-1],max(dp[i][j-1],dp[i-1][j]));
                }
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    
                    
            }
        }
        return dp[m][n];
    }
};