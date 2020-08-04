/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (35.95%)
 * Likes:    1272
 * Dislikes: 3024
 * Total Accepted:    617.8K
 * Total Submissions: 1.7M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "race a car"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * s consists only of printable ASCII characters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    char lower(char c)
    {
        if((c>='a' and c<='z') or (c>='0' and c<='9'))
            return c;
        return 'a' + c-'A';
    }
    bool isAlpha(char c)
    {
        if(( c>='a' and c<='z') or (c>='A' and c<='Z') or (c>='0' and c<='9'))
            return true;
        return false;
    }
    bool isPalindrome(string s) {
        
        int i = 0;
        int j = s.size()-1;

        while(i<j)
        {
            if(!isAlpha(s[i]))
            {
                i++;
                continue;
            }
            if(!isAlpha(s[j]))
            {
                j--;
                continue;
            }
            if(lower(s[i])!=lower(s[j]))
                return false;
            i++;
            j--;
        }
        return true;
    }
};
// @lc code=end

