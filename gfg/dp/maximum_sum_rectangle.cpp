#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
/* Problem link
https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle/0
*/


void maximum_sum_rectangle(vector<vector<int>> A)
{
	int m = A.size();      // row 
	int n = A[0].size();  //  colmun

	
	int MSRsum = A[0][0];
	int MSRl = 0;
	int MSRr = 0;
	int MSRt = 0;
	int MSRd = 0;

	int l = 0;
	int r = 0;

	for(;l<n;l++)
	{
		vector<int> v(m,0);

		for(r=l;r<n;r++)
		{
			for(int j=0;j<m;j++)
			{
				v[j] += A[j][r];
			}

			// Find Max Sum subarray and update the rectangle
			int maxSum = 0;
			int maxIndex = 0;
			int index = 0;
			int sum = 0;
			int maxLength = 0;
			int length = 0;

			for(int j=0;j<m;j++)
			{
				sum += v[j];
				length++;
				if(sum > maxSum)
				{
					maxSum = sum;
					maxIndex = index;
					maxLength = length;
				}
				if(sum<0)
				{
					sum = 0;
					length = 0;
					index = j+1;

				}

			}

			if(maxSum>MSRsum)
			{
				MSRsum = maxSum;
				MSRl = l;
				MSRr = r;
				MSRt = maxIndex;
				MSRd = maxIndex + maxLength -1;
			}

		}
	}

	cout<<MSRsum<<endl;;
	// cout<<"rectangle ="<<MSRl<<" "<<MSRr<<" "<<MSRt<<" "<<MSRd<<endl;
	// return MSRsum;
}
int main()
{
	int m,n;
	int t;
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
	maximum_sum_rectangle(v);
}
	//cout<<"hello"<<endl;
	return 0;
}