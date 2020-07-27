#include <bits/stdc++.h>
using namespace std;

/* counting sort
	3 steps 
	1) Count the occurence of element in count array
	2) Calcualte the next index vector where we are going to store the arr[i]
	3) Fill in the output array
*/

// for positive numbers range
void countSort(vector<int>& a,int k)
{
	// k is inclusive in the range
	vector<int> count(k+1,0);
	int n = a.size();
	// store the occurence of each element
	for(int i:a)
		count[i]++;

	//calculate the next index vector
	int num_so_far = 0;
	for(int i=0;i<=k;i++)
	{
		int c = count[i];
		count[i]=num_so_far;
		num_so_far += c;
	}
	vector<int> output(n,0);
	// fill in the output array
	for(int i:a)
	{
		output[count[i]]=i;
		count[i]++;
	}

	// copy the output array into the 
	for(int i=0;i<n;i++)
		a[i]=output[i];
}
// Map the numbers from 0 to range
void countSort2(vector<int> &a)
{
	int mn = *min_element(a.begin(),a.end());
	int mx = *max_element(a.begin(),a.end());

	// this range is k
	int range = mx-mn+1;

	for(int i=0;i<a.size();i++)
		a[i]-=mn;

	countSort(a,range);

	for(int i=0;i<a.size();i++)
		a[i]+=mn;

}