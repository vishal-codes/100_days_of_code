class Solution {
public:
    int minSetSize(vector<int>& arr) {
    
        unordered_map<int,int> m;
        int n = arr.size();
        for(int i=0;i<arr.size();i++)
        {
            m[arr[i]]++;
        }
        vector<pair<int,int>> s;
        
        for(auto it=m.begin();it!=m.end();it++)
        {
            // cout<<it->second<<" "<<it->first<<endl;
            s.push_back({it->second,it->first});
        }
        sort(s.begin(),s.end(),greater<pair<int,int>>());
        int h = n/2;
        int ans = 0;
        int i = 0;
        while(n>h and i<s.size())
        {
            pair<int,int> p = s[i];
            n=n-p.first;
            ans++;
            i++;
        }
        return ans;
    }
};