/*
Problem link
https://leetcode.com/problems/target-sum/
*/
class Solution {
public:
    int subsetSum(vector<int> &nums,int S)
    {
        int n = nums.size();
        if(S==0)
        {
            int c = 0;
            for(int i=0;i<n;i++)
            {
                if(nums[i]==0)c++;
            }
            return pow(2,c);
        }
        
          int dp[n+1][S+1];
     for(int i=0;i<=S;i++)
     {
         dp[0][i]=0;
     }
     dp[0][0]=1;
     for(int i=1;i<=n;i++)
     {
         if(nums[i-1]==0)
         {
             dp[i][0]=2*dp[i-1][0];
         }
         else
         dp[i][0]=1;
     }
     for(int i=1;i<=n;i++)
     {
         for(int j=1;j<=S;j++)
         {
             if(nums[i-1]<=j)
             {
                 dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
             }
             else
                 dp[i][j]=dp[i-1][j];
         }
     }
     return dp[n][S];   
    }
    int findTargetSumWays(vector<int>& nums, int d) {
      int sum = 0,i,j;
        int a[nums.size() + 1];
        for(i = 0; i < nums.size(); i++){
            a[i + 1] = nums[i];
            sum += nums[i];
        }
        if(d > sum)
            return 0;
        if((d - sum) & 1)
            return 0;
        int n = nums.size(),m = (sum - d)/2;
        int dp[n + 1][m + 1];
        dp[0][0] = 1;
        for(i = 1; i <= n; i++){
            if(a[i] == 0)
                dp[i][0] = 2*dp[i - 1][0];
            else
                dp[i][0] = dp[i - 1][0];
        }
        for(i = 1; i <= m; i++){
            dp[0][i] = 0;
        }
        for(i = 1; i <= n; i++){
            for(j = 1; j <= m; j++){
                if(a[i] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i]];
            }
        }
        return dp[n][m];    }
};