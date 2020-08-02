/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 */

// @lc code=start
class Solution {
public:
    int openLock(vector<string>& d, string target) {
        
        
        int n = d.size();
        queue<string> q;
        
        unordered_map<string,int> m;
        for(int i=0;i<d.size();i++)
        {
            m[d[i]]++;
        }
        if(m.find("0000")==m.end()){
        q.push("0000");
        m["0000"]++;
    }
        int step = 0;
        while(!q.empty())
        {
            step ++;
            int s = q.size();
            for(int i=0;i<s;i++)
            {
                string c = q.front();
                q.pop();
                if(c==target)
                {
                    return step-1;
                }
                for(int j=0;j<4;j++)
                {
                    int n = (c[j]-'0'+1)%10+'0';
                    string t = c.substr(0,j)+(char)n+c.substr(j+1);
                    if(m.find(t)==m.end())
                    {
                        q.push(t);
                        m[t]++;
                    }
                }
                for(int j=0;j<4;j++)
                {
                    int n = (c[j]-'0'-1+10)%10+'0';
                    string t = c.substr(0,j)+(char)n+c.substr(j+1);
                    if(m.find(t)==m.end())
                    {
                        q.push(t);
                        m[t]++;
                    }
                }

            }
        }
        return -1;
    }
};
// @lc code=end

