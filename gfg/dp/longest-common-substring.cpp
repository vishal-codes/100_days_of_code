/*
 Problem link https://practice.geeksforgeeks.org/problems/longest-common-substring/0
  */
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int lcs(string A,string B)
{
	int m=A.size();
	int n=B.size();
	int dp[m+1][n+1];
    int ans = 0;
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0 or j==0){
				dp[i][j]=0;
				continue;
			}
			if(A[i-1]==B[j-1])
			{
				dp[i][j]=1+dp[i-1][j-1];
			}
			else
			{
				dp[i][j]=0;
			}
			ans=max(ans,dp[i][j]);
		}
	}
	return ans;
}
int main()
{
	int t;
	cin>>t;

	while(t--){
	int m,n;
	string A,B;
	cin>>m>>n;
	cin>>A>>B;

	cout<<lcs(A,B)<<endl;;
}
}
