/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (41.94%)
 * Likes:    1986
 * Dislikes: 121
 * Total Accepted:    180.4K
 * Total Submissions: 429.4K
 * Testcase Example:  '10'
 *
 * Write a program to find the n-th ugly number.
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3,
 * 5. 
 * 
 * Example:
 * 
 * 
 * Input: n = 10
 * Output: 12
 * Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
 * ugly numbers.
 * 
 * Note:  
 * 
 * 
 * 1 is typically treated as an ugly number.
 * n does not exceed 1690.
 * 
 */

// @lc code=start
#define ll long long
class Solution {
public:
    int nthUglyNumber(int n) {
        set<ll> s;
    s.insert(1);
    
    while(n--)
    {
        ll a = *(s.begin());
        s.erase(s.begin());
        if(n==0)
        {
            return a;
        }
        s.insert(a*2);
        s.insert(a*3);
        s.insert(a*5);
        
    }
        return 1;
    }
};
// @lc code=end

