#include<bitset>
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        
        for(int i=0;i<m;i++)
        {
            if(A[i][0]==0)
            {
                for(int j=0;j<n;j++)
                {
                    A[i][j]=1-A[i][j];
                }
            }
        }
        
        for(int j=1;j<n;j++)
        {
            int z=0;
            int o=0;
            for(int i=0;i<m;i++)
            {
                if(A[i][j]==0)
                    z++;
                else
                    o++;
            }
            if(z>o)
            {
                for(int i=0;i<m;i++)
                    A[i][j]=1-A[i][j];
            }
            
        }
        
        int ans = 0;
        for(int i=0;i<m;i++)
        {
            string s = "";
            for(int j=0;j<n;j++)
            {
                s+=to_string(A[i][j]);
            }
            // cout<<s<<endl;
            bitset<32> bits(s);
            ans  += bits.to_ulong();
        }
        return ans;
    }
};