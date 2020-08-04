/*
 * @lc app=leetcode id=319 lang=cpp
 *
 * [319] Bulb Switcher
 *
 * https://leetcode.com/problems/bulb-switcher/description/
 *
 * algorithms
 * Medium (45.37%)
 * Likes:    489
 * Dislikes: 1028
 * Total Accepted:    79.7K
 * Total Submissions: 175.7K
 * Testcase Example:  '3'
 *
 * There are n bulbs that are initially off. You first turn on all the bulbs.
 * Then, you turn off every second bulb. On the third round, you toggle every
 * third bulb (turning on if it's off or turning off if it's on). For the i-th
 * round, you toggle every i bulb. For the n-th round, you only toggle the last
 * bulb. Find how many bulbs are on after n rounds.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: 1 
 * Explanation: 
 * At first, the three bulbs are [off, off, off].
 * After first round, the three bulbs are [on, on, on].
 * After second round, the three bulbs are [on, off, on].
 * After third round, the three bulbs are [on, off, off]. 
 * 
 * So you should return 1, because there is only one bulb is on.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countDivisor(int n)
    {
        int i = 1;
        int c = 0;
        while(i*i<=n)
        {
            if(i*i==n)
                c=c+1;
            else
                c=c+2;
            i++;
        }
        return c;
    }
    int bulbSwitch(int n) {
        int ans = 0;
        for(int i=1;i<=n;i++)
        {
            int a = sqrt(i);
            if(a*a==i)
            {
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

