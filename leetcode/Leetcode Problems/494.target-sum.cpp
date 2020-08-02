/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 *
 * https://leetcode.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (46.38%)
 * Likes:    2714
 * Dislikes: 110
 * Total Accepted:    170.9K
 * Total Submissions: 368.5K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * You are given a list of non-negative integers, a1, a2, ..., an, and a
 * target, S. Now you have 2 symbols + and -. For each integer, you should
 * choose one from + and - as its new symbol.
 * 
 * Find out how many ways to assign symbols to make sum of integers equal to
 * target S.
 * 
 * Example 1:
 * 
 * 
 * Input: nums is [1, 1, 1, 1, 1], S is 3. 
 * Output: 5
 * Explanation: 
 * 
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 * 
 * There are 5 ways to assign symbols to make the sum of nums be target 3.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The length of the given array is positive and will not exceed 20.
 * The sum of elements in the given array will not exceed 1000.
 * Your output answer is guaranteed to be fitted in a 32-bit integer.
 * 
 * 
 */

// @lc code=start
#define ll long long
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {

        ll s = 0;
        for(int i:nums)
        {
            s+=i;
        }
        if(S>s)
        {
            return 0;
        }
        if((s+S)%2)
            return 0;        
        ll t = (s+S)/2;
        int n = nums.size();
        int m = t;
        // cout<<t<<endl;
        int dp[n+1][m+1];

        for(int i=0;i<=m;i++)
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
                dp[i][0]=dp[i-1][0];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(nums[i-1]<=j)
                {
                    dp[i][j]= dp[i-1][j]+dp[i-1][j-nums[i-1]];

                }
                else 
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][t];
    }
};
// @lc code=end

