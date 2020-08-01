/* Dynamic programming approach but first think recursively
   Thinks how can you check for a word;

   example , s = catsanddog
             dict = ['cats','and','dog']

    So, now iterate over s , and choose a substring of s starting with index 0 from 
    the begining , now if the substring is in dict check , then remaing string s entirely
    a new subproblem. If the remaining string can be split then ans is true, otherwise 
    keep iterating ans repeat the steps.

*/
class Solution {
public:
    int helper(string &s,unordered_map<string,int>& m,int start,vector<int>& dp)
    {
        // comments
        
        int n = s.size();
        if(start>=n)
        {
            return true;
        }
        if(dp[start]!=-1)
        {
            return dp[start];
        }
        string temp = "";
        for(int i=start;i<n;i++)
        {
            temp += s[i];
            if(m.find(temp)!=m.end())
            {
                if(helper(s,m,i+1,dp))
                {
                    dp[start]=1;
                    return dp[start];
                }
            }
        }
        dp[start]=0;
        return dp[start];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
     int n = s.size();
     vector<int> dp(n,-1);
     unordered_map<string,int> m;
    
     for(string s1 : wordDict)
     {
         m[s1]++;
     }
     return helper(s,m,0,dp);
     
    }
};