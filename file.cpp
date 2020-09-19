#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back

void solve()
{
    ll n;
    
    cin>>n;
    vector<ll> v1(n),v2(n);
    for(ll i=0;i<n;i++)
        cin>>v1[i];
    for(ll i=0;i<n;i++)
        cin>>v2[i];
    vector<pair<ll,ll>> v;
    for(ll i=0;i<n;i++)
    {
        v.pb({v1[i],v2[i]});
    }
    sort(v.begin(),v.end());
    int mxt = -1;
    int mxp = -1;
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    for(ll i=0;i<n;i++)
    {
        while(!pq.empty() and pq.top()<v[i].first)
        {
            pq.pop();
        }
        ll d = pq.size()+1;

        if(d>mxp)
        {
            mxp=d;
            mxt=v[i].first;
        }
        pq.push(v[i].second);
    }
    cout<<mxp<<" "<<mxt<<endl;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}