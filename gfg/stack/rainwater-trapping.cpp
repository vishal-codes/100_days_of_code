#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void maxRight(vector<ll>& v,vector<ll>& right)
{
  stack<ll> s;
  ll mx = INT_MIN;
  for(ll i=v.size()-1;i>=0;i--)
  {
    mx=max(mx,v[i]);
    right[i]=mx;
  }
}
void maxLeft(vector<ll>& v,vector<ll>& right)
{
  stack<ll> s;
  ll mx = INT_MIN;
  for(ll i=0;i<v.size();i++)
  {


    mx=max(mx,v[i]);
        right[i]=mx;
  }

}

ll rainwaterTrapping(vector<ll>& v)
{
  ll n = v.size();
  vector<ll> left(n);
  vector<ll> right(n);
  maxLeft(v,left);
  maxRight(v,right);

  ll ans = 0;
  for(ll i=0;i<n;i++)
  {
    // cout<<left[i]<<" ";
    if(left[i]!=-1 and right[i]!=-1)
    {
      // cout<<v[i]<<endl;
      ans+=min(left[i],right[i])-v[i];
    }
  }
  // cout<<endl;
  // for(ll i=0;i<n;i++)
    // cout<<right[i]<<" ";;
  // cout<<endl;
  return ans;
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    ll n;
    cin>>n;
    vector<ll> v(n);
    ll i = 0;
    while(n--)
    {
      cin>>v[i];
      i++;
    }
    cout<<rainwaterTrapping(v)<<endl;;
  }
}