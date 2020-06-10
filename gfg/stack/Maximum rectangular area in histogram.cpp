// https://practice.geeksforgeeks.org/problems/next-larger-element/0
#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
void nextSmallerLeft(vector<long long> &v,vector<long long>& nextSm)
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
void nextSmallerRight(vector<long long> &v,vector<long long>& nextSm)
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
int main()
{
  fast;
  long long t;
  cin>>t;
  while(t--)
  {
    long long n;
    cin>>n;
    vector<long long> v(n);
    for(long long i=0;i<n;i++)
    {
      cin>>v[i];
    }
    vector<long long> left(n);
    vector<long long> right(n);
    nextSmallerLeft(v,left);
    nextSmallerRight(v,right);
    long long ans = 0;
    for(long long i=0;i<n;i++)
    {
      ans = max(ans,(left[i]+right[i]-1)*v[i]);
    }
    cout<<ans<<endl;
  }
}