class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = index.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
           // cout<<index[i]<<" ";
            if(ans.size()==index[i])
            {
                ans.push_back(nums[i]);
            }
            else
            {
                vector<int> v;
                int i1 = index[i];
                
                for(int j=i1;j<ans.size();j++)
                {
                    v.push_back(ans[j]);
                }
                
                ans[i1]=nums[i];
                i1++;
                for(int j=0;j<v.size()-1;j++)
                {
                    ans[i1]=v[j];
                    i1++;
                }
                ans.push_back(v[v.size()-1]);
            
            }
        }
        return ans;
    }
};