/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (29.40%)
 * Likes:    7460
 * Dislikes: 558
 * Total Accepted:    988.1K
 * Total Submissions: 3.4M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string str) {
          int n = str.size();
        if(n<=1)
            return str;
        int ans = 0;
        int mxstart;
        int mxend;
        int start;
        int end;
        for(int i=0;i<n;i++)
        {
            int s = i;
            int e = i;
            while(s>=0 and e<n)
            {
                if(str[s]==str[e])
                {
                    start=s;
                    end = e;
                    s--;
                    e++;
                }
                else
                    break;
            }
            int l = e-s-1;
            if(l>ans)
            {
                mxstart = start;
                mxend = end;
                ans = l;
            }
        }
        
        // even length
         for(int i=0;i<n;i++)
        {
            int s = i;
            int e = i+1;
            while(s>=0 and e<n)
            {
                if(str[s]==str[e])
                {
                    start=s;
                    end = e;
                    s--;
                    e++;
                }
                else
                    break;
            }
            int l = e-s-1;
            if(l>ans)
            {
                mxstart = start;
                mxend = end;
                ans = l;
            }
        }
        string a;
        for(int i=mxstart;i<=mxend;i++)
        {
            a = a+str[i];
        }
        return a;   
    }
};
// @lc code=end

