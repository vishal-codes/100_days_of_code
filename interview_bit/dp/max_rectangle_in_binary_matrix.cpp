#define ll long long
ll largest_histogram(vector<ll>& v)
{
    ll n = v.size();
    stack<ll> s;
    ll i = 0;
    ll max_area = 0;
    
    while(i<n)
    {
        if(s.empty() or v[s.top()]<=v[i])
        {
            s.push(i);
            i++;
        }
        else
        {
            ll t = s.top(); // element
            s.pop();
            
            ll a = 0;
            
            if(s.empty()) // left index is zero
            {
                a = v[t]*i;
            }
            else  // left index is s.top()
            {
                a = v[t]*(i-s.top()-1);
            }
            max_area = max(max_area,a);
        }
    }
        while(!s.empty())
        {
             ll t = s.top(); // element
            s.pop();
            
            ll a = 0;
            
            if(s.empty()) // left index is zero
            {
                a = v[t]*i;
            }
            else  // left index is s.top()
            {
                a = v[t]*(i-s.top()-1);
            }
            max_area = max(max_area,a);
        }
    return max_area;
}
int Solution::maximalRectangle(vector<vector<int> > &A) {

    int m = A.size(); // rows
    int n = A[0].size(); // column;
    vector<int> v(n,0);
    int ans = 0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(A[i][j]==1)
                v[j] +=A[i][j];
            else
                v[j]=0; 
        }
        ans = max(ans,largest_histogram(v));
    }
    return ans;
}