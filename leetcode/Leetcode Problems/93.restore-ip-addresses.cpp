/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (35.50%)
 * Likes:    1299
 * Dislikes: 507
 * Total Accepted:    197.6K
 * Total Submissions: 556.2K
 * Testcase Example:  '"25525511135"'
 *
 * Given a string containing only digits, restore it by returning all possible
 * valid IP address combinations.
 * 
 * A valid IP address consists of exactly four integers (each integer is
 * between 0 and 255) separated by single points.
 * 
 * Example:
 * 
 * 
 * Input: "25525511135"
 * Output: ["255.255.11.135", "255.255.111.35"]
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    vector<string> helper(string s,int n)
    {
        vector<string> ans ;
        if(n==1)
        {
            
            
            if(s!="" and s.size()<=3)
            {
                int a = stoi(s);
                if(a==0 and s.size()==1)
                {
                    ans.push_back(s);
                }
                else if((a>=1 and a<=255) and s[0]!='0')
                {
                    ans.push_back(s);
                }
            }
            
            
            return ans;
        }
        int a = 0;
        for(int i=0;i<3 and i<s.size();i++)
        {
            a = a*10 + (s[i]-'0');

            if(a==0 and i==0)
            {
                vector<string> sub = helper(s.substr(i+1),n-1);
                for(int j=0;j<sub.size();j++)
                {
                    string t = s.substr(0,i+1)+'.'+sub[j];
                    ans.push_back(t);
                }
            }
            if((a>=1 and a<=255) and s[0]!='0'){
                vector<string> sub = helper(s.substr(i+1),n-1);
                for(int j=0;j<sub.size();j++)
                {
                    string t = s.substr(0,i+1)+'.'+sub[j];
                    ans.push_back(t);
                }
            }
        }
        return ans;
    }
    vector<string> restoreIpAddresses(string s) {
        return helper(s,4);
    }
};
// @lc code=end

