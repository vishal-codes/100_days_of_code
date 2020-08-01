/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */

// @lc code=start 
class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int n = word.size();
        bool allCaps = true;
        bool allSmall = true;
        int c = 0;
        for(int i=0;i<n;i++)
        {
            if(word[i]<='Z' and word[i]>='A')
            {
                c++;
            } 
        }
        if(c==0 or c==n)
            return true;
        if(c==1 and (word[0]<='Z' and word[0]>='A'))
            return true;
        return false;
    }
};
// @lc code=end

