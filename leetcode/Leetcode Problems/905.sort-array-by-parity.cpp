/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 *
 * https://leetcode.com/problems/sort-array-by-parity/description/
 *
 * algorithms
 * Easy (73.94%)
 * Likes:    1024
 * Dislikes: 73
 * Total Accepted:    207.2K
 * Total Submissions: 280K
 * Testcase Example:  '[3,1,2,4]'
 *
 * Given an array A of non-negative integers, return an array consisting of all
 * the even elements of A, followed by all the odd elements of A.
 * 
 * You may return any answer array that satisfies this condition.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [3,1,2,4]
 * Output: [2,4,3,1]
 * The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 5000
 * 0 <= A[i] <= 5000
 * 
 * 
 * 
 */

// @lc code=start

    bool compare(const int & a,const int & b)
    {
        if(a%2==0)
        {
            if(b%2==0)
            {
                return a<=b;
            }
            return true;
        }
        if(b%2==0)
        {
            if(a%2==0)
            {
                return a<=b;
            }
            return false;
        }
        return a<=b;
    }
class Solution {
public:

    vector<int> sortArrayByParity(vector<int>& A) {

     
        vector<int> o;
        vector<int> e;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]%2)
            {
                o.push_back(A[i]);
            }
            else 
                e.push_back(A[i]);
        }
        for(int i=0;i<o.size();i++)
        {
            e.push_back(o[i]);
        }
        return e;
    }
};
// @lc code=end

