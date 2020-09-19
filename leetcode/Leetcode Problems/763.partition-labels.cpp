/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 *
 * https://leetcode.com/problems/partition-labels/description/
 *
 * algorithms
 * Medium (75.90%)
 * Likes:    2565
 * Dislikes: 122
 * Total Accepted:    136.1K
 * Total Submissions: 178.8K
 * Testcase Example:  '"ababcbacadefegdehijhklij"'
 *
 * A string S of lowercase English letters is given. We want to partition this
 * string into as many parts as possible so that each letter appears in at most
 * one part, and return a list of integers representing the size of these
 * parts.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: S = "ababcbacadefegdehijhklij"
 * Output: [9,7,8]
 * Explanation:
 * The partition is "ababcbaca", "defegde", "hijhklij".
 * This is a partition so that each letter appears in at most one part.
 * A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it
 * splits S into less parts.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * S will have length in range [1, 500].
 * S will consist of lowercase English letters ('a' to 'z') only.
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string S) {
            int a[26]={0};
        int n = S.size();
        for(int i=0;i<n;i++)
        {
            a[S[i]-'a']=i;
        }
        
        vector<int> ans;
        
        int s = 0;
        
        int e = -1;
        
        for(int i=0;i<n;i++)
        {
            if(e==-1)
            {
                e=a[S[i]-'a'];
            }
            if(i==e)
            {
                ans.push_back(e-s+1);
                s=i+1;
                e=-1;
            }
            else if(a[S[i]-'a']>e)
            {
                e=a[S[i]-'a'];
            }
        }
        return ans; 
    }
};
// @lc code=end

