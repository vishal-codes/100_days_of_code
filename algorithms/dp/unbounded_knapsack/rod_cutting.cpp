#include<bits/stdc++.h>
using namespace std;
int ans(int dp[],int n,int x,int y,int z)
{
    if(n<=0)
    {
        return 0;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    int a = 0;
    int b = 0;
    int c = 0;
    if(n-x>=0){a=ans(dp,n-x,x,y,z)+1;}
    if(n-y>=0){b=ans(dp,n-y,x,y,z)+1;}
    if(n-z>=0){c=ans(dp,n-z,x,y,z)+1;}
    dp[n]=max(a,max(b,c));
    return dp[n];
}
int main() {
	//code
	int t,N,x,y,z;
	cin>>t;
	while(t--)
	{
	    
	    cin>>N>>x>>y>>z;
	    int dp[N+1];
	    memset(dp,-1,sizeof(dp));
	   cout<< ans(dp,N,x,y,z)<<endl;;
	}
	return 0;
}