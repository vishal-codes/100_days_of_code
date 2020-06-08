int maxSumSubarray(vector<int> v)
{
    int n = v.size();
    int maxSum = INT_MIN;
    int s = 0;
    for(int i=0;i<n;i++)
    {
        s=s+v[i];
        maxSum=max(maxSum,s);
        if(s<0)
        {
            s=0;
        }
    }
    return maxSum;
}
int Solution::solve(vector<vector<int> > &A) {
    
    int ans = INT_MIN;
    int m = A.size();
    if(m<=0)
    {
        return 0;
    }
    int n = A[0].size();
    vector<int> v(m,0);
    
    for(int j=n-1;j>=0;j--)
    {
        bool isAllNegative=true;
        for(int i=0;i<m;i++)
        {
            v[i]+=A[i][j];
            if(v[i]>0)
            {
                isAllNegative=false;
            }
        }
        ans=max(ans,maxSumSubarray(v));
        if(isAllNegative)
        {
            for(int i=0;i<m;i++)
            v[i]=0;
        }
    }
    return ans;
    
}
