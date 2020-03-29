#define pb push_back
int Solution::fibsum(int n) {

    if(n==1 or n==2 or n==3)
    {
        return 1;
    }
    
    vector<int> fib(51);
    fib[0]=1;
    fib[1]=1;
    
    int i = 2;
    for(;i<45;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }
    //  cout<<" "<<i<<" "<<fib[i-1]<<endl;
    int ans = 0;
    i=i-1;
    while(n>0 and i>0)
    {
        if((n-fib[i])>=0)
        {
            // cout<<" i="<<i<<" "<<fib[i]<<" ";
            n = n - fib[i];
            ans++;
        }
        else
            i--;
    }
    // cout<<endl;
    return ans;
}
