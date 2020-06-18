class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
       unordered_map<int,vector<int>> m;
       int n = nums.size();
        if(n<=0)
        {
            vector<int> a;
            return a;
        }
       sort(nums.begin(),nums.end());
       m[n-1].push_back(nums[n-1]);
       
       for(int i=n-2;i>=0;i--)
       {
           vector<int> a;
           int mx=0;
           for(int j=i+1;j<n;j++)
           {
               if(nums[j]%nums[i]==0)
               {
                   if(m[j].size()>mx)
                   {
                       mx=m[j].size();
                       a=m[j];
                   }
               }
           }
           a.push_back(nums[i]);
           m[i]=a;
       }
       vector<int> a;
       for(auto it=m.begin();it!=m.end();it++)
       {
           vector<int> &b=(*it).second;
           if(b.size()>a.size())
               a=b;
       }
        return a;
        
        
    }
};