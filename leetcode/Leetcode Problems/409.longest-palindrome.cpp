/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 *
 * https://leetcode.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (50.29%)
 * Likes:    1140
 * Dislikes: 86
 * Total Accepted:    165.9K
 * Total Submissions: 322.2K
 * Testcase Example:  '"abccccdd"'
 *
 * Given a string which consists of lowercase or uppercase letters, find the
 * length of the longest palindromes that can be built with those letters.
 * 
 * This is case sensitive, for example "Aa" is not considered a palindrome
 * here.
 * 
 * Note:
 * Assume the length of given string will not exceed 1,010.
 * 
 * 
 * Example: 
 * 
 * Input:
 * "abccccdd"
 * 
 * Output:
 * 7
 * 
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        int a[256]={};
        for(char c:s)
        {
            a[c]++;
        }
        bool one = false;
        int ans=0;
        for(int i=0;i<256;i++)
        {
            
            if(a[i]%2==0) 
            ans += a[i];
            else
            {
                ans+=a[i]-1;
                one=true;
            }
        }
        if(one)
        ans++;
        return ans ;
    }
};
// @lc code=end

