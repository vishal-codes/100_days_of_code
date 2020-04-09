#include <iostream>
#include<vector>
using namespace std;
//https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items/0
int unbounded_knapsack(vector<int>& weight,vector<int> &val,int n,int W)
{
    int dp[n+1][W+1];
    for(int i=0;i<=W;i++)
    {
        dp[0][i]=0;
    }
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(weight[i-1]<=j)
            {
                dp[i][j]=max((dp[i][j-weight[i-1]]+val[i-1]),dp[i-1][j]);
            }
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][W];
}
int main() {
	int t,n,w;
	cin>>t;
	while(t--)
	{
	    cin>>n>>w;
	    vector<int> weight(n);
	    vector<int> val(n);
	   
	    for(int i=0;i<n;i++)
	    {
	        cin>>val[i];
	    }
	     for(int i=0;i<n;i++)
	    {
	        cin>>weight[i];
	    }
	    cout<<unbounded_knapsack(weight,val,n,w)<<endl;;
	}
	return 0;
}