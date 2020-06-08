#include<bits/stdc++.h>
using namespace std;
/*
https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0/
*/
int helper(vector<vector<int>> &dp,int K,int N)
{
        if(K==1 )
        {
            return N;
        }
          if(N==1 or N==0)
        {
            return N;
        }
        if(dp[K][N]!=-1)
        {
            return dp[K][N];
        }
        int mn=INT_MAX;
        for(int i=1;i<=N;i++)
        {
            int lower ;
            int upper ;
            if(dp[K-1][i-1]!=-1)
            {
                lower=dp[K-1][i-1];
            }
            else
            {
                lower=helper(dp,K-1,i-1);
                dp[K-1][i-1]=lower;
            }
            if(dp[K][N-i]!=-1)
            {
                upper=dp[K][N-i];
            }
            else
            {
                upper=helper(dp,K,N-i);
                dp[K][N-i]=upper;
            }
            int temp=1+max(upper,lower);
            mn=min(mn,temp);
        }
        dp[K][N]=mn;
        return mn;
    }
int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K+1,vector<int>(N+1,-1));
        int ans = helper(dp,K,N);
        
        // for(int i=0;i<=K;i++)
        // {
        //     for(int j=0;j<=N;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        // cout<<endl;
        // }
        return ans;
}
int main()
{
    int t,k,n;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        cout<<superEggDrop(k,n)<<endl;
    }
}
