/* 
Problem Link - https://practice.geeksforgeeks.org/problems/minimum-deletitions/0
*/
#include <bits/stdc++.h>
using namespace std;
int lcs(string& A,string& B)
{
    int m = A.size();
    int n = B.size();
    
    int dp[m+1][n+1];
    
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 or j==0)
            dp[i][j]=0;
            else{
            if(A[i-1]==B[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    return dp[m][n];
}
int lps(string& A)
{
    string B = A;
    reverse(B.begin(),B.end());
    // cout<<A<<" "<<B<<endl;
    return lcs(A,B);
    
}
int solve(string &A)
{
    return A.size()-lps(A);
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