int Solution::bulbs(vector<int> &A) {
    int n = A.size();
    if(n<=0)
    {
        return 0;
    }
    
    int ans = 0;
    for(int i=n-2;i>=0;i--)
    {
        if(A[i]!=A[i+1])
        {
            ans ++;
        }
    }
    if(A[0]==0)
    {
        ans++;
    }
    return ans;
}
