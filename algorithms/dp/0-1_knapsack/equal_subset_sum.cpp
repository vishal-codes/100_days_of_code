#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
/* Problem link
https://practice.geeksforgeeks.org/problems/subset-sum-problem/0
*/

// recursive soln
bool subset_sum(vector<int>& a,int n,int sum)
{
	if(n==0 )
	{
		return sum==0;
	}

	if(sum==0) return true;


	if(a[n-1]<=sum)
	{
		return subset_sum(a,n-1,sum-a[n-1]) || subset_sum(a,n-1,sum);

	}
	else
		return subset_sum(a,n-1,sum);
}

// dp
bool subset_sum2(vector<int>& a,int n,int sum)
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
			sum+=a[i];
		}
		bool ans;
		if(sum%2)
			ans=false;
		else
			ans = subset_sum2(a,n,sum/2);

		if(ans)cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;

	}
	return 0;
}