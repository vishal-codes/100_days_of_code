class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
    unordered_map<string,vector<string>> m;
    int n = s.size();
    for(int i=0;i<n;i++)
    {
        string temp = s[i];
        sort(temp.begin(),temp.end());
        m[temp].push_back(s[i]);
    }
    vector<vector<string>> ans;
    for(auto it=m.begin();it!=m.end();it++)
    {
        ans.push_back(it->second);
    }
    return ans;
    }
};