class Solution {
public:
    int numTeams(vector<int>& arr) {
        
        int n = arr.size();
        //increasing order rating
        vector<int> l(n);
        vector<int> s(n);
        for(int i=0;i<n;i++)
        {
        
            l[i]=0;
            s[i]=0;
            for(int j=i+1;j<n;j++)
            {
                if(arr[j]>arr[i])
                {
                    l[i]++;
                }
                else if(arr[j]<arr[i])
                    s[i]++;
                    
                
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[j]>arr[i])
                {
                    ans = ans + l[j];
                }
                else if(arr[j]<arr[i])
                {
                    ans = ans + s[j];
                }
            }
        }
        return ans;
    }
};