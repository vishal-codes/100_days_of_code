#define ll long long
int Solution::maxProduct(const vector<int> &A) {
    ll n = A.size();
    vector<ll> v(n);
    vector<ll> v2(n);
    ll mx = A[0];
    v[0]=v2[0]=A[0];
    
    for(ll i=1;i<n;i++)
    {
        
        ll a = A[i];
        v[i]=max(a,max(a*v[i-1],a*v2[i-1]));
        v2[i]=min(a,min(a*v[i-1],a*v2[i-1]));
        mx=max(mx,max(v[i],v2[i]));
    }
    return mx;
}
