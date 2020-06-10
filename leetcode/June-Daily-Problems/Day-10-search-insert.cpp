class Solution {
public:
    int bs(vector<int>& nums,int i,int j,int target)
    {
        if(i>j)
        {
            return i;
        }
        int m = (i+j)/2;
        if(nums[m]==target)
        {
            return m;
        }
        if(nums[m]<target)
        {
            return bs(nums,m+1,j,target);
        }
        return bs(nums,i,m-1,target);
    }
    int searchInsert(vector<int>& nums, int target) {
        return bs(nums,0,nums.size()-1,target);
    }
};