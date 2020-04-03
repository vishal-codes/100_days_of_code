int p(int n,int power[])
{
    if(n==1)
    {
        return 0;
    }
    if(n<=1000 and power[n]!=-1)
    {
        return power[n];
    }
    int ans =1;
    if(n%2)
    {
        ans += p(3*n+1,power);
    }
    else
    {
        ans += p(n/2,power);
    }
    if(n<=1000)
    power[n]=ans;
    return ans;
}
int p2(int n)
{
    if(n==1)
    {
        return 0;
    }
    int ans = 1;
    if(n%2)
        ans = ans + p2(3*n+1);
    else
        ans = ans +p2(n/2);
    return ans;
}
class Solution {
public:
    int getKth(int lo, int hi, int k) {
        int power[1005];
        memset(power,-1,sizeof(power));
        power[0]=-1;
        power[2]=1;
        power[3]=7;
        for(int i=4;i<=1000;i++)
        {
            if(power[i]==-1)
            {
                power[i]=p(i,power);
            }
        }
        // for(int i=1;i<=10;i++)
        // {
        //     cout<<i<<" "<<power[i]<<endl;
        // }
        set<pair<int,int>> s;
        for(int i=lo;i<=hi;i++)
        {
            s.insert({power[i],i});
        }
        int i = 1;
        auto it = s.begin();
        // while(it!=s.end())
        // {
        //     cout<<(*it).first<<" "<<(*it).second<<endl;
        //     it++;
        // }
        it=s.begin();
        while(i<k)
        {
            it++;
            i++;
        }
        return (*it).second;
    }
};