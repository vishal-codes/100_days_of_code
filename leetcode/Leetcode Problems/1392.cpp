class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n);
        lps[0]=0;
        int i=0;
        int j=1;
        while(j<n)
        {
            if(s[i]==s[j])
            {
                i=i+1;
                lps[j]=i;
                j=j+1;
            }
            else
            {
                if(i!=0)
                {
                    i=lps[i-1];
                }
                else
                {
                    lps[j]=0;
                    j++;
                }
            }
        }
        string ans;
        // cout<<lps[n-1]<<" ";
        for( i=0;i<lps[n-1];i++)
            ans+=s[i];
        return ans;
    }
};