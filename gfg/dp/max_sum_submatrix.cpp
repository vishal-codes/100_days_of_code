#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
/* Problem link
https://practice.geeksforgeeks.org/problems/max-sum-submatrix/0
*/


void maximum_sum_submatrix(vector<vector<int>> &A,int m,int n)
{
	int dp[m+1][n+1];
	dp[0][0]=A[0][0];
	for(int i=1;i<m;i++)
	{
		dp[i][0]=dp[i-1][0]+A[i][0];
	}

	for(int i=1;i<n;i++)
	{
		dp[0][i]=dp[0][i-1]+A[0][i];
	}

	for(int i=1;i<m;i++)
	{
		for(int j=1;j<n;j++)
		{
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + A[i][j];
		}
	}

	int q;
	cin>>q;
	int a,b;
	while(q--)
	{
		cin>>a>>b;
		int ans = INT_MIN;
		for(int i=0;i<=m-a;i++)
		{
			for(int j=0;j<=n-b;j++)
			{
				int sum = dp[i+a-1][j+b-1];
				if(j-1>=0)
				{
					sum -= dp[i+a-1][j-1];
				}
				if(i-1>=0)
				{
					sum -= dp[i-1][j+b-1];
				}
				if(i-1>=0 and j-1>=0)
				{
					sum += dp[i-1][j-1];
				}
				ans=max(ans,sum);
			}
		}
		cout<<ans<<" ";
	}
	cout<<endl;

}
int main()
{
	int t;
	int m,n;
	cin>>t;
	while(t--)
	{
	vector<vector<int>> v;
	cin>>m>>n;

	for(int i=0;i<m;i++)
	{
		vector<int> a;
		int b;
		for(int j=0;j<n;j++)
		{
			cin>>b;
			a.push_back(b);
		}
		v.push_back(a);

	}
	maximum_sum_submatrix(v,m,n);
	}
	return 0;
}
