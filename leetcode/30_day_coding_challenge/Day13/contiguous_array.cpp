class Solution {
public:
    int findMaxLength(vector<int>& nums) {
     
        for(int i=0;i<nums.size();i++)
        {
            if(!nums[i])nums[i]=-1;    
        }
        map<int,int> m;
        m[0]=0;
        int sum = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum = sum + nums[i];
            if(m.find(sum)!=m.end())
            {
                int cl = i - m[sum];
                // cout<<sum<<" "<<i<<" "<<m[i]<<endl;
                if(sum==0)
                    cl++;
                ans = max(ans,cl);
            }
            else{
                // cout<<"Why you are not executing bro ??"<<endl;
                m[sum]=i;
            }
        }
        return ans;
        
    }
};