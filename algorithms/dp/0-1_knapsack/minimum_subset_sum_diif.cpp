#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
/* Problem link
https://practice.geeksforgeeks.org/problems/minimum-sum-partition/0
*/


// dp
int minimum_sum_partition(vector<int>& a,int n,int sum)
{
	bool t[n+1][sum+1];

	for(int j=0;j<=sum;j++)
		t[0][j]=false;

	for(int i=0;i<=n;i++)
		t[i][0]=true;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			
			 if(a[i-1]<=j)
				t[i][j] = t[i-1][j] || t[i-1][j-a[i-1]];
			else
				t[i][j] = t[i-1][j];
		}
	}
	

	int ans = INT_MAX;

	for(int i=0;i<=sum;i++)
	{
		if(t[n][i])
		{
			ans = min(ans,abs(2*i-sum));
		}
	}
	return ans;
}
int main()
{
	int t,n,W;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<int> a(n);
		
		int sum = 0;
		for(int i=0;i<n;i++)
		{

			cin>>a[i];
			sum+=a[i];
			
		}
		
		int ans;
	
			ans = minimum_sum_partition(a,n,sum);

				cout<<ans<<endl;

	}
	return 0;
}