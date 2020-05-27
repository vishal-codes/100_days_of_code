class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0) nums[i]=-1;
        }
        
        unordered_map<int,int> m;
        m[0] = -1;
        long sum = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum = sum + nums[i];
            if(m.find(sum)!=m.end())
            {
                int cl = i - m[sum];
                ans = max(ans,cl);
            }
            else
                m[sum]=i;
        }
        return (int)ans;
    }
};