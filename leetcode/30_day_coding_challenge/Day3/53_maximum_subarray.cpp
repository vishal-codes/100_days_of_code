class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     long long sum = 0;
     int n = nums.size();
     long long ans = INT_MIN;
     for(int i=0;i<n;i++)
     {
         sum += nums[i];
         ans = max(ans,sum);
         if(sum<0)
         {
             sum=0;
         }
     }
     return ans;
    }
};