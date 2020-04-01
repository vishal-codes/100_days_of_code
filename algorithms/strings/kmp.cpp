#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
// LPS stands for longest common prefix which is also suffix of the array
// LPS[j] is the value of longest common prefix which is also suffix for the string
// starting at index 0 and ending at index j
void computeLPS(string s,vector<int>& lps)
{
    int n = s.size();
    int i = 0 ;
    int j = 1;
    lps.resize(n);
    lps[0]=0;
    while(j<n)
    {
        if(s[i]==s[j])
        {
            i++;
            lps[j]=i;
            j++;

        }
        else
        {
            if(i!=0)
            {
                // This is tricky
                // take the example AAACAAAA and i = 7
                i=lps[i-1];
            }
            else
            {
                lps[j]=0;
                j++;
            }
        }
    }
}
void KMP(string text,string pattern)
{
    vector<int> lps;
    computeLPS(pattern,lps);
    int i = 0; // pointing to the text
    int j = 0; // pointing to the pattern
    int n = text.size();
    int m = pattern.size();
    while(i<n)
    {
        if(text[i]==pattern[j])
        {
            i++;
            j++;
        }

        if(j==m)
        {
            cout<<"Pattern found at index "<<i-j<<endl;
            // setting j to the find the next index of pattern
            j = lps[j-1];
        }
        else if(i<n and text[i]!=pattern[j])
        {
            if(j!=0)
            j=lps[j-1];
            else
            i++;

        }
    }

}

int main()
{
    string text ="dsgawdxdsgawd";
    string pattern = "dsgawd";
    KMP(text,pattern);
}