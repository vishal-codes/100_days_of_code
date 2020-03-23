#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
/* Problem link
https://practice.geeksforgeeks.org/problems/perfect-sum-problem/0
*/


// dp
int count_of_subset_sum(vector<int>& a,int n,int sum)
{
	int t[n+1][sum+1];

	for(int j=0;j<=sum;j++)
		t[0][j]=0;

	for(int i=0;i<=n;i++)
		t[i][0]=1;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			
			 if(a[i-1]<=j)
				t[i][j] = t[i-1][j] + t[i-1][j-a[i-1]];
			else
				t[i][j] = t[i-1][j];
		}
	}
	return t[n][sum];
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
			
		}
		cin>>sum;
		int ans;
	
			ans = count_of_subset_sum(a,n,sum);

				cout<<ans<<endl;

	}
	return 0;
}