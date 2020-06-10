// https://practice.geeksforgeeks.org/problems/next-larger-element/0
#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
void nextLargerElement(vector<long long> &v)
{
  long long n = v.size();
  vector<long long> nextgr(n);
  stack<long long> s;
  for(long long i=0;i<n;i++)
  {
    if(s.empty())
    {
      nextgr[i]=-1;
    }
    else
    {
      while(!s.empty() and v[s.top()]<=v[i])
      {
        s.pop();
      }
      if(s.empty())
      {
        nextgr[i]=-1;
      }
      else
      {
        nextgr[i]=s.top();
      }
    }
    s.push(i);
  }

  for(long long i=0;i<n;i++)
  {
    nextgr[i]=i-nextgr[i];
    cout<<nextgr[i]<<" ";
  }
  cout<<endl;

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
    nextLargerElement(v);
  }
}