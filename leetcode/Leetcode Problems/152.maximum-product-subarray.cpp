/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (31.66%)
 * Likes:    4338
 * Dislikes: 161
 * Total Accepted:    346.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 * 
 */

// @lc code=start
#define ll long long
class Solution {
public:
    int maxProduct(vector<int>& a) {
        
        int n = a.size();
        vector<ll> dp(n);
        dp[n-1]=a[n-1];
        ll mx = a[n-1];
        for(int i=n-2;i>=0;i--)
        {
            dp[i]=max((ll)a[i],dp[i+1] * (ll)a[i]);
            mx = max(mx,dp[i]);
        }
        return mx;
    }
};
// @lc code=end

