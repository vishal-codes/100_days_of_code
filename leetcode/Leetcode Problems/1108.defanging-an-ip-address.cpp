/*
 * @lc app=leetcode id=1108 lang=cpp
 *
 * [1108] Defanging an IP Address
 */

// @lc code=start
class Solution {
public:
    string defangIPaddr(string address) {
          string ans ;
        for(int i=0;i<adress.size();i++)
        {
            if(adress[i]=='.')
                ans += "[.]";
            else
                ans += adress[i];
        }
        return ans;
    }
    }
};
// @lc code=end

