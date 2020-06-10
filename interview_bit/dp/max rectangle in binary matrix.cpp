#define ll long long
ll maxAreaHistogram(vector<ll> &A)
{

	// next-left-smaller-array
	ll n = A.size();
	vector<ll> left(n);
	stack<ll> s;
	for(ll i=0;i<n;i++)
	{
		while(!s.empty() and A[s.top()]>=A[i])
		{
			s.pop();
		}
		if(s.empty())
		{
			left[i]=-1;
		}
		else
			left[i]=s.top();
		s.push(i);
	}

	while(!s.empty())
		s.pop();
	// next-right-smaller-array
	vector<ll> right(n);
	for(ll i=n-1;i>=0;i--)
	{
		while(!s.empty() and A[s.top()]>=A[i])
		{
			s.pop();
		}
		if(s.empty())
		{
			right[i]=n;
		}
		else
			right[i]=s.top();
		s.push(i);
	}
	ll maxArea=0;
	for(ll i=0;i<n;i++)
	{
		left[i]=abs(i-left[i]);
		right[i]=abs(i-right[i]);
		maxArea=max(maxArea,(left[i]+right[i]-1)*A[i]);
	}
	return maxArea;
}
int Solution::maximalRectangle(vector<vector<int> > &A) {
	ll m = A.size();
	if(m<=0)
	{
		return 0;
	}
	ll n = A[0].size();
	vector<ll> v(n,0);
	ll maxArea=0;
	for(ll i=0;i<m;i++)
	{
		for(ll j=0;j<n;j++)
		{
			if(A[i][j])
				v[j]+=A[i][j];
			else
				v[j]=0;
		}
		maxArea=max(maxArea,maxAreaHistogram(v));
	}
	return maxArea;
}
