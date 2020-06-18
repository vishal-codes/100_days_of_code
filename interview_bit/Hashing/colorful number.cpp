#define ll long long
int Solution::colorful(int A) {
    unordered_map<ll,ll> m;
    string s = to_string(A);
    int n = s.size();
    for(int i=0;i<n;i++)
    {
        ll count = 1;
        string s1 = "";
        for(int j=i;j<n;j++)
        {
            s1 +=s[j];
            ll temp = stoi(s1);
            count =temp*count;
            if(m.find(count)!=m.end())
            {
                return 0;
            }
            m[count]++;
            s1="";
        }
    }
    return 1;
}
