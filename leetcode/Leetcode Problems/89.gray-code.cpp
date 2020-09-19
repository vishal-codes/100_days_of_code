/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 *
 * https://leetcode.com/problems/gray-code/description/
 *
 * algorithms
 * Medium (49.06%)
 * Likes:    664
 * Dislikes: 1572
 * Total Accepted:    164.7K
 * Total Submissions: 334.7K
 * Testcase Example:  '2'
 *
 * The gray code is a binary numeral system where two successive values differ
 * in only one bit.
 * 
 * Given a non-negative integer n representing the total number of bits in the
 * code, print the sequence of gray code. A gray code sequence must begin with
 * 0.
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: [0,1,3,2]
 * Explanation:
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 * 
 * For a given n, a gray code sequence may not be uniquely defined.
 * For example, [0,2,3,1] is also a valid gray code sequence.
 * 
 * 00 - 0
 * 10 - 2
 * 11 - 3
 * 01 - 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 0
 * Output: [0]
 * Explanation: We define the gray code sequence to begin with 0.
 * A gray code sequence of n has size = 2^n, which for n = 0 the size is 2^0 =
 * 1.
 * Therefore, for n = 0 the gray code sequence is [0].
 * 
 * 
 */

// @lc code=start
#define pb push_back
class Solution {
public:
    int toDecimal(string s)
    {
        int d = 0;
        int p = 1;
        for(int i=s.size()-1;i>=0;i--)
        {
            d += (s[i]-'0')*p;
            p=p*2;
        }
        return d;
    }
    vector<string> helper(int n)
    {
        vector<string> ans;
        if(n==0)
        {
            ans.pb("0");
            return ans;
        }
        if(n==1)
        {
            ans.pb("0");
            ans.pb("1");
            return ans;
        }
        vector<string> sub = helper(n-1);
        for(string s:sub)
        {
            ans.pb("0"+s);
        }
        reverse(sub.begin(),sub.end());
        for(string s:sub)
        {
            ans.pb("1"+s);
        }
        return ans;
    }
    vector<int> grayCode(int n) {
        
        vector<string> codes =helper(n);
        vector<int> ans;
        for(string s:codes)
        {
            ans.pb(toDecimal(s));
        }
        return ans;

    }
};
// @lc code=end

