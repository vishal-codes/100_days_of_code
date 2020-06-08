class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<pair<int,int>> p;
        vector<vector<int>> ans;
        int n = people.size();
        if(n==0)
            return ans;
        for(vector<int>v :people)
        {
                p.push_back({v[1],v[0]});
        }
        
        sort(p.begin(),p.end());
        
        // for(int i=0;i<n;i++)
        // {
        //     cout<<p[i].first<<" "<<p[i].second<<endl;
        // }
        vector<int> v;
        v.push_back(p[0].second);
        v.push_back(p[0].first);
        ans.push_back(v);
        
        for(int i=1;i<n;i++)
        {
            int count = p[i].first;
            if(count==0)
            {
                
                   vector<int> a;
                   a.push_back(p[i].second);
                   a.push_back(p[i].first);
                   ans.push_back(a);
                    continue;
            }
            int j = 0;
            int c = 0;
            while(j<ans.size() and c<count)
            {
                if(ans[j][0]>=p[i].second)
                {
                    c++;
                }
                
                    j++;
            }
            if(j==ans.size())
            {
                   vector<int> a;
                   a.push_back(p[i].second);
                   a.push_back(p[i].first);
                   ans.push_back(a);
                
            }
            else
            {
                       vector<int> a;
                       a.push_back(p[i].second);
                       a.push_back(p[i].first);
                       ans.push_back(a);
                        
                        int k = ans.size()-2;
                        while(k!=j-1)
                        {
                            ans[k+1]=ans[k];
                            k--;
                        }
                        ans[j]=a;
                        k=j;
                        while(k<ans.size()-1 and ans[k][0]>ans[k+1][0])
                        {
                            swap(ans[k],ans[k+1]);
                            k++;
                        }
                        
            }
        }
        return ans;
    }
};