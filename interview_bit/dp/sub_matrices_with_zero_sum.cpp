#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
/* Problem link
https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle/0
*/


int  sub_matrices_with_zero_sum(vector<vector<int>> A)
{
	int m = A.size();      // row 
	int n = A[0].size();  //  colmun
	int ans = 0;
	

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
			int sum = 0;
			int count = 0;
			unordered_map<int,int>map;
			for(int j=0;j<m;j++)
			{
				sum += v[j];
				if(sum==0 or map.find(sum)!=map.end())
				{
					count++;
				}
				map[sum]++;
			}
			if(count==m)
			{
				count = ((m)*(m+1))/2;
			}
			ans = ans + count;

		}
	}

	return ans;
	// cout<<"rectangle ="<<MSRl<<" "<<MSRr<<" "<<MSRt<<" "<<MSRd<<endl;
	// return MSRsum;
}
int sum(int* arr, int n) {
    unordered_map<int, int> prevSum; 
    int res = 0; 
    int currsum = 0; 
    for (int i = 0; i < n; i++) { 
        currsum += arr[i]; 
        if (currsum == 0)  
            res++;         
        if (prevSum.find(currsum) !=prevSum.end())  
            res += (prevSum[currsum]); 
        prevSum[currsum]++; 
    } 
  return res; 
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
	cout<<sub_matrices_with_zero_sum(v)<<endl;;
}
	//cout<<"hello"<<endl;
	return 0;
}