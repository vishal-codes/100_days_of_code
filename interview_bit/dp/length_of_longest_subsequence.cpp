int Solution::longestSubsequenceLength(const vector<int> &A) {

    int n = A.size();
    vector<int> lis(n);
    vector<int> lds(n);
    lis[0]=1;
    lds[n-1]=1;
    for(int i=1;i<n;i++)
    {
        lis[i]=1;
        for(int j=0;j<i;j++)
        {
            if(A[j]<A[i])
            {
                lis[i]=max(lis[1],lis[j]+1);
            }
        }
    }
    
    for(int i=n-2;i>=0;i--)
    {
        for(int j=i+1;j<n;j++)
        {
            if(A[j]>A[j])
            {
                lds[i]=max()
            }
        }
    }
}
