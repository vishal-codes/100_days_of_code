int Solution::canJump(vector<int> &A) {
    
    int n = A.size();
    if(n<=1)
    {
        return 1;
    }
    int minPossibleIndex = n-1;
    
    for(int i=n-2;i>=0;i--)
    {
        int isPossible = 0;
        if(i+A[i]>=minPossibleIndex)
        {
            isPossible=1;
            minPossibleIndex=i;
        }
        if(i==0)
        {
            return isPossible;
        }
    }
    return 1;
}
