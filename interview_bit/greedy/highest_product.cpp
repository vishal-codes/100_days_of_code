int Solution::maxp3(vector<int> &A) {

    
    sort(A.begin(),A.end());
    int n = A.size();
    int a = A[0];
    int b = A[1];
    int c = INT_MIN;
    if(a<0 and b<0)
    {
     c = a*b*A[n-1];
    }
    return max(c,A[n-1]*A[n-2]*A[n-3]);   
}