int Solution::adjacent(vector<vector<int> > &A) {
    // dp 
    int n = A[0].size();
    int t[n+1];
    t[0]=0;
    t[1]=max(A[0][0],A[1][0]);

    for(int i=2;i<=n;i++)
    {
        t[i]=max(t[i-1],t[i-2]+max(A[0][i-1],A[1][i-1]));
    }
    return t[n];
}
