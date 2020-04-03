int Solution::mice(vector<int> &A, vector<int> &B) {
    int ans = INT_MIN;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int n = A.size();
    
    for(int i=0;i<n;i++)
    {
        int a = abs(B[i]-A[i]);
        ans = max(a,ans);
    }
    return ans;
}
