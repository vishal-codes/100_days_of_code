#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
/* Problem link
https://practice.geeksforgeeks.org/problems/subarray-with-0-sum/0
*/
bool subarray_with_0_sum(vector<int> &a,int n)
{
	int sum = 0;
	unordered_map<int,int> map;
	for(int i=0;i<n;i++)
	{
		sum += a[i];
		if(sum==0 or map.find(sum)!=map.end())
		{
			return true;
		}
		map[sum]++;
	}
	return false;
}
int main()
{
	int m,n,b;
	int t;
	cin>>t;
	while(t--)
	{
	vector<int> v;
	cin>>n;


		for(int j=0;j<n;j++)
		{

			cin>>b;
			v.push_back(b);
		}
		
	if(subarray_with_0_sum(v,n))
	{
		cout<<"Yes"<<endl;;
	}
	else
		cout<<"No"<<endl;
}
	//cout<<"hello"<<endl;
	return 0;
}