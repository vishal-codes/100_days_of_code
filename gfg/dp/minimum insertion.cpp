/*
https://practice.geeksforgeeks.org/problems/form-a-palindrome/0
*/
#include <bits/stdc++.h>
using namespace std;
int lcs(string A,string B)
{
    int m = A.size();
    int n = B.size();
    
    int** dp = new int*[m+1];
    for(int i=0;i<=m;i++)
        dp[i]=new int[n+1];
    
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 or j==0)
                dp[i][j]=0;
            else
            {
                if(A[i-1]==B[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int ans = dp[m][n];
    for(int i=0;i<=m;i++)
        delete dp[i];
    delete []dp;
    
    return ans;
}
int solve(string A)
{
    string B = A;
    reverse(B.begin(),B.end());
    return A.size()-lcs(A,B);
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string A;
	    cin>>A;
	    cout<<solve(A)<<endl;
	}
	return 0;
}