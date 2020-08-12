/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 *
 * https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
 *
 * algorithms
 * Medium (66.06%)
 * Likes:    2494
 * Dislikes: 155
 * Total Accepted:    201.9K
 * Total Submissions: 299.2K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements
 * appear twice and others appear once.
 * 
 * Find all the elements that appear twice in this array.
 * 
 * Could you do it without extra space and in O(n) runtime?
 * 
 * Example:
 * 
 * Input:
 * [4,3,2,7,8,2,3,1]
 * 
 * Output:
 * [2,3]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> findDuplicates(vector<int>& a) {
        
        vector<int> ans;
        for(int i=0;i<a.size();i++)
        {
           
            while(1)
            {
                int b = a[i];
                if(b==0 or b==i+1)
                {
                    break;
                }
                else
                {
                    if(a[b-1]==0)
                        break;
                    if(a[b-1]==b)
                    {
                        ans.push_back(b);
                        a[b-1]=0;
                        break;
                    }
                    else
                    {
                        swap(a[i],a[b-1]);
                    }
                }
                
            }
        }
        return ans;
    }
};
// @lc code=end

