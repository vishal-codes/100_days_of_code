class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        set<pair<long,pair<int,int>>> s;
        for(int i=0;i<points.size();i++)
        {
            long a = (long )points[i][0];
            long b = (long )points[i][1];
            s.insert({a*a+b*b,{points[i][0],points[i][1]}});
        }
        int i = 0;
        vector<vector<int>> ans;
        auto it = s.begin();
        while(it!=s.end() and i<K )
        {
            pair<long,pair<int,int>> p = *it;
            vector<int> a ;
            a.push_back(p.second.first);
            a.push_back(p.second.second);
            ans.push_back(a);
            it++;
            i++;
        }
        return ans;
    }
};