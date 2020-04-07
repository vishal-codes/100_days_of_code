class Solution {
public:
    int countElements(vector<int>& a) {
     unordered_map<int,int> m;
     int n = a.size();
     for(int i=0;i<n;i++)m[a[i]]++;
     long long ans = 0;
     for(int i=0;i<n;i++)
     {
         if(m.find(a[i]+1)!=m.end())
            ans++;
     }
            return ans;
    }
};