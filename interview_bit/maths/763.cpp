class Solution {
public:
    vector<int> partitionLabels(string S) {
        
        int a[26]={0};
        int n = S.size();
        for(int i=0;i<n;i++)
        {
            a[S[i]-'a']=i;
        }
        
        vector<int> ans;
        
        int s = 0;
        
        int e = -1;
        
        for(int i=0;i<n;i++)
        {
            if(e==-1)
            {
                e=a[S[i]-'a'];
            }
            if(i==e)
            {
                ans.push_back(e-s+1);
                s=i+1;
                e=-1;
            }
            else if(a[S[i]-'a']>e)
            {
                e=a[S[i]-'a'];
            }
        }
        return ans;
    }
};