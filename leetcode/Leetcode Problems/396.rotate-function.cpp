/*
 * @lc app=leetcode id=396 lang=cpp
 *
 * [396] Rotate Function
 */

// @lc code=start
#define ll long long
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        
        int n = A.size();
        if(n<=0)
        return 0;
        ll sum = 0;
        for(int i:A) 
        {
            sum = sum + (ll)i;
        }

        ll a = 0;       
        for(int i=0;i<n;i++)
        {
            a += (ll)i * (ll)A[i];
        }
        ll mx = a;
        for(int i=1;i<n;i++)
        {

            ll s = a + sum - ((ll)n*(ll)A[n-i]);
            mx = max(s,mx);
            a=s;
        }
        return mx;
    }
};
// @lc code=end

