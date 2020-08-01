/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */

// @lc code=start
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,0));
        
        dp[m-1][n-1]=dungeon[m-1][n-1]>0?1:abs(dungeon[m-1][n-1])+1;
        
        for(int i=m-2;i>=0;i--)
        {
            dp[i][n-1]=max(dp[i+1][n-1]-dungeon[i][n-1],1);
        }
        
        for(int i=n-2;i>=0;i--)
        {
            dp[m-1][i]=max(dp[m-1][i+1]-dungeon[m-1][i],1);
        }
        for(int i=m-2;i>=0;i--)
        {
            for(int j=n-2;j>=0;j--)
            {
                dp[i][j]=  max(min(dp[i+1][j],dp[i][j+1])-dungeon[i][j],1);
            }
        }
        return dp[0][0];;
    }
};
// @lc code=end

