/*
https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence/0
*/
#include <iostream>
using namespace std;

int lrs(string A)
{
    int n = A.size();
    int dp[n+1][n+1];
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 or j==0)
            dp[i][j]=0;
            
            else
            {
                if(A[i-1]==A[j-1] and i!=j)
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int z;
	    cin>>z;
	    string a;
	    cin>>a;
	    cout<<lrs(a)<<endl;
	}
	return 0;
}