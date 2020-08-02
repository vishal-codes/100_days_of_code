/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        
        int n = T.size();
        vector<int> ans;

        if(n<=0)
            return ans;

        
        ans.resize(n);
        ans[n-1]=-1; 
        vector<int> v(n);
        v[n-1]=0;
        stack<int> s;
        s.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            if(s.empty())
            {
                ans[i]=-1;
                v[i]=0;
            }
            else
            {
                while(!s.empty() and T[s.top()]<=T[i])
                {
                
                    
                        s.pop();
                    
                }
                if(s.empty())
                {
                    ans[i]=-1;
                    v[i]=0;
                }
                else
                {
                    ans[i]=s.top();
                    v[i]=ans[i]-i;
                }
            }
            s.push(i);
        }
        return v;
    }
};
// @lc code=end

