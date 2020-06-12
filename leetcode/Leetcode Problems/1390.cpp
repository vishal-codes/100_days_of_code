class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        long long ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            ans += numDivisors(nums[i]);
        }
        return (int)ans;
    }
    
    static long long numDivisors(int n)
    {
        vector<int> ans;
        for(int i=1;i<=sqrt(n);i++)
        {
            if(n%i==0){
            if(i*i==n)
            {
                ans.push_back(i);
            }
            else
            {
                ans.push_back(i);
                ans.push_back(n/i);
            }
            }
            if(ans.size()>4)
            {
                break;
            };
        }
        long long sum =0;
        if(ans.size()==4)
        {
            for(int i=0;i<4;i++)
                sum +=ans[i];
        }
        return sum;
    }
};