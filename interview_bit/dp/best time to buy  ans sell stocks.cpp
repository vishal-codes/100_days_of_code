int Solution::maxProfit(const vector<int> &A) {
    
    int n = A.size();
    vector<int> v(n);
    int mx = INT_MIN;
    int ans = 0;
    for(int i=n-1;i>=0;i--)
    {
        mx=max(mx,A[i]);
        v[i]=mx;
        ans = max(ans,v[i]-A[i]);
    }
    return ans;
    
}
