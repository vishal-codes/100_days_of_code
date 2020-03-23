#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
/* Problem link
https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
*/

// recursive soln
int knapsack(vector<int>& weight,vector<int>& cost,int n,int capacity)
{
	if(n==0 or capacity==0)
	{
		return 0;
	}

	if(weight[n-1]<=capacity)
	{
		return max(knapsack(weight,cost,n-1,capacity-weight[n-1]),knapsack(weight,cost,n-1,capacity));

	}
	else
		return knapsack(weight,cost,n-1,capacity);
}

// dp
int knapsack2(vector<int>& weight,vector<int>& cost,int n,int capacity)
{
	int t[n+1][capacity+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=capacity;j++)
		{
			if(i==0 or j==0)
				t[i][j] = 0;
			else if(weight[i-1]<=j)
				t[i][j] = max(t[i-1][j],t[i-1][j-weight[i-1]]+cost[i-1]);
			else
				t[i][j] = t[i-1][j];
		}
	}
	return t[n][capacity];
}
int main()
{
	int t,n,W;
	cin>>t;
	while(t--)
	{
		cin>>n>>W;
		vector<int> w(n),c(n);
		
		for(int i=0;i<n;i++)
			cin>>c[i];
		
		for(int i=0;i<n;i++)
			cin>>w[i];

		

		cout<<knapsack2(w,c,n,W)<<endl;;
	}
	return 0;
}