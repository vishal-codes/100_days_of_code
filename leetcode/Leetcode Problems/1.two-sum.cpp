/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(m.find(target-nums[i])!=m.end())
            {
                vector<int> v;
                v.push_back(m[target-nums[i]]);
                v.push_back(i);
                return v;
            }
            m[nums[i]]=i;
            
        }
        vector<int> v;
        return v;
    }
};
// @lc code=end

