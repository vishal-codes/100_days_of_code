/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 *
 * https://leetcode.com/problems/ransom-note/description/
 *
 * algorithms
 * Easy (53.05%)
 * Likes:    643
 * Dislikes: 200
 * Total Accepted:    227.5K
 * Total Submissions: 428.8K
 * Testcase Example:  '"a"\n"b"'
 *
 * Given an arbitrary ransom note string and another string containing letters
 * from all the magazines, write a function that will return true if the ransom
 * note can be constructed from the magazines ; otherwise, it will return
 * false.
 * 
 * Each letter in the magazine string can only be used once in your ransom
 * note.
 * 
 * 
 * Example 1:
 * Input: ransomNote = "a", magazine = "b"
 * Output: false
 * Example 2:
 * Input: ransomNote = "aa", magazine = "ab"
 * Output: false
 * Example 3:
 * Input: ransomNote = "aa", magazine = "aab"
 * Output: true
 * 
 * 
 * Constraints:
 * 
 * 
 * You may assume that both strings contain only lowercase letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        int a[257]={};
        for(int i=0;i<magazine.size();i++)
        {
            a[magazine[i]]++;
        }

        for(int i=0;i<ransomNote.size();i++)
        {
            if(a[ransomNote[i]]<=0)
            {
                return false;
            }
            a[ransomNote[i]]--;
        }
        return true;
    }
};
// @lc code=end

