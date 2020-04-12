class Solution {
public:
    int search(vector<int> &p,int m,int q)
    {
      
        return -1;
    }
    vector<int> processQueries(vector<int>& queries, int m) {
        
        vector<int> v;
        for(int i= 1;i<=m;i++){
            v.push_back(i);
        }
        vector<int> res;
        for(auto it:queries){
            for(int i = 0;i<v.size();i++){
                if(v[i]==it){
                    res.push_back(i);
                    for(int k=i-1;k>=0;k--){
                        swap(v[k+1],v[k]);
                    }
                    break;
                }
            }
        }
        return res;
        
    }
};