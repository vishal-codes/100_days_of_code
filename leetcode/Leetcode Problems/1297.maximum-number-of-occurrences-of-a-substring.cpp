/*
 * @lc app=leetcode id=1297 lang=cpp
 *
 * [1297] Maximum Number of Occurrences of a Substring
 *
 * https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/description/
 *
 * algorithms
 * Medium (47.16%)
 * Likes:    167
 * Dislikes: 135
 * Total Accepted:    10.4K
 * Total Submissions: 22K
 * Testcase Example:  '"aababcaab"\n2\n3\n4'
 *
 * Given a string s, return the maximum number of ocurrences of any substring
 * under the following rules:
 * 
 * 
 * The number of unique characters in the substring must be less than or equal
 * to maxLetters.
 * The substring size must be between minSize and maxSize inclusive.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
 * Output: 2
 * Explanation: Substring "aab" has 2 ocurrences in the original string.
 * It satisfies the conditions, 2 unique letters and size 3 (between minSize
 * and maxSize).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
 * Output: 2
 * Explanation: Substring "aaa" occur 2 times in the string. It can overlap.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "aabcabcab", maxLetters = 2, minSize = 2, maxSize = 3
 * Output: 3
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "abcde", maxLetters = 2, minSize = 3, maxSize = 3
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * 1 <= maxLetters <= 26
 * 1 <= minSize <= maxSize <= min(26, s.length)
 * s only contains lowercase English letters.
 * 
 */

// @lc code=start
class Solution {
public:

    int numUnique(string s,int start,int end)
    {
        int a[26]={};
        int c = 0;
        for(int i=start;i<=end;i++)
        {
            if(a[s[i]-'a']==0)
            {
                c++;
            }
            a[s[i]-'a']=1;
        }
        return c;
    }
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        
        int mx = 0;
        
        map<string, int> mp;

        vector<int> cnt(26, 0);

        string str;
        int unique = 0;
        for(int i = 0; i < minSize; i++) {
            if(cnt[s[i] - 'a']++ == 0) {
                unique++;
            }
            str += s[i]; 
        }
        if(unique <= maxLetters) {
            mp[str]++;
            mx = max(mx, mp[str]);
        }
        for(int i = minSize; i < s.size(); i++) {
            if(cnt[s[i] - 'a']++ == 0) {
                unique++;
            }
            if(--cnt[s[i - minSize] - 'a'] == 0) {
                unique--;
            }
            str += s[i];
            str.erase(str.begin());
            if(unique <= maxLetters) {
                mp[str]++;
                mx = max(mx, mp[str]);
            }
        }
        
        return mx;
    }
};
// @lc code=end

