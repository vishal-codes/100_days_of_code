/*
problem link - https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication/0
*/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &dp,vector<int> &a,int i,int j)
{
	if(i>=j)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	long ans = INT_MAX;

	for(int k=i;k<j;k++)
	{
		long ans1 = solve(dp,a,i,k);
		long ans2 = solve(dp,a,k+1,j);
		long ans3 = ans1+ans2+a[i-1]*a[k]*a[j];
		ans = min(ans3,ans);
	}
	return dp[i][j]=ans;
}

int mcm(vector<int> &a)
{
	int n = a.size();
	vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

	return solve(dp,a,1,a.size()-1);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		cout<<mcm(a)<<endl;
	}
}	