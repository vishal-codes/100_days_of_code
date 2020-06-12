class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int n = light.size();
        vector<int> v(n);
        fill(v.begin(),v.end(),0);
        int ans1 = 0;
        for(int i=0;i<n;i++)
        {
            int bulb = light[i]-1;
            v[bulb]=1;
            if(bulb==0)
            {
            
                int j = bulb;
                for(;j<n;j++)
                {
                    if(v[j]==1 )
                    {
                        v[j]=2;
                    }
                    else
                        break;
                }
                if(j-1==i)
                    ans1++;
            }
            else
            {
                if(v[bulb-1]==2)
                {
                    int j = bulb;
                    for(;j<n;j++)
                    {
                        if(v[j]==1)
                        {
                            v[j]=2;
                        }
                        else
                            break;
                    }
                    if(j-1==i)
                        ans1++;
                }
            }
        
        }
          return ans1;
    }
};