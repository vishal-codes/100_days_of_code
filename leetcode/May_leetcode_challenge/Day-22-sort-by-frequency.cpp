class Solution {
public:
    string frequencySort(string s) {
        
        
        unordered_map<char,int> m;
        
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
        
        vector<pair<int,char>> v;
        for(auto it=m.begin();it!=m.end();it++)
        {
            v.push_back({(*it).second,(*it).first});
        }
        sort(v.begin(),v.end());
        string ans;
        for(int i=v.size()-1;i>=0;i--)
        {
            for(int j=0;j<v[i].first;j++)
            {
                ans += v[i].second;
            }
        }
        return ans;
        
    }
};