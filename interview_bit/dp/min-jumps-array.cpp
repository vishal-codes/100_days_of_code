int Solution::jump(vector<int> &A) {

    int f = 0;
    int e = 0;
    int n = A.size();
    int j = 0;
    for(int i=0;i<n-1;i++)
    {
        f = max(f,i+A[i]);
        if(f<n-1 && i==f)
        {
            return -1;
        }
        if(i==e)
        {
            e=f;
            j++;
        }
    }
    return j;
}
