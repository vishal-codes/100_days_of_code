class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& c) {
        
        
        set<pair<int,pair<int,int>>> s;
        int twoN = c.size();
        int n = twoN>>1;
        
        for(int i=0;i<twoN;i++)
        {
            s.insert({abs(c[i][0]-c[i][1]),{c[i][0],c[i][1]}});
            // cout<<abs(c[i][0]-c[i][1])<<" "<<c[i][0]<<" "<<c[i][1]<<endl;
        }
        
        long ans = 0;
        int i = 0;
        int j = 0;
        auto it=s.rbegin();
        while(it!=s.rend() and (i<n and j<n))
        {
            pair<int,pair<int,int>> p = *it;
            int d = p.second.first-p.second.second;
            if(d<0)
            {
                ans += p.second.first;
                i++;
            }
            else{
                ans += p.second.second;
                j++;}
            it++;
        }
        
        while(it!=s.rend() and i<n)
        {
            pair<int,pair<int,int>> p = *it;
            ans += p.second.first;
            i++;
            it++;
        }
        
        while(it!=s.rend() and j<n)
        {
            pair<int,pair<int,int>> p = *it;
            ans += p.second.second;
            j++;
            it++;
        }
        // cout<<j<<" "<<j<<endl;
        return ans;
    }
};