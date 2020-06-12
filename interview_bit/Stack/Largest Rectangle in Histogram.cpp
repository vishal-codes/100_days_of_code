void nextSmallerLeft(vector<int> &v,vector<int>& nextSm)
{
  long long n = v.size();
  // vector<long long> nextSm(n);
  stack<long long> s;
  for(long long i=0;i<n;i++)
  {
    if(s.empty())
    {
      nextSm[i]=-1;
    }
    else
    {
      while(!s.empty() and v[s.top()]>=v[i])
      {
        s.pop();
      }
      if(s.empty())
      {
        nextSm[i]=-1;
      }
      else
      {
        nextSm[i]=s.top();
      }
    }
    s.push(i);
  }

  for(long long i=0;i<n;i++)
  {
    nextSm[i]=i-nextSm[i];
    // cout<<nextSm[i]<<" ";
  }
  // cout<<endl;
  // return nextSm;

}
void nextSmallerRight(vector<int> &v,vector<int>& nextSm)
{
  long long n = v.size();
  // vector<long long> nextSm(n);
  stack<long long> s;
  for(long long i=n-1;i>=0;i--)
  {
    if(s.empty())
    {
      nextSm[i]=n;
    }
    else
    {
      while(!s.empty() and v[s.top()]>=v[i])
      {
        s.pop();
      }
      if(s.empty())
      {
        nextSm[i]=n;
      }
      else
      {
        nextSm[i]=s.top();
      }
    }
    s.push(i);
  }

  for(long long i=0;i<n;i++)
  {

    nextSm[i]=abs(i-nextSm[i]);
    // cout<<nextSm[i]<<" ";
  }
  // cout<<endl;
  // return nextSm;

}
int Solution::largestRectangleArea(vector<int> &A) {

    int n = A.size();
    vector<int> left(n);
    vector<int> right(n);
    nextSmallerLeft(A,left);
    nextSmallerRight(A,right);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans = max(ans, (left[i]+right[i]-1)*A[i]);
    }
    return ans;
    
}
