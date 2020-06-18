vector<int> Solution::twoSum(const vector<int> &A, int B) {
    unordered_map<int,int> m;
    pair<int,int> p = {-1,-1};
    for(int i=0;i<A.size();i++)
    {
        if(m.find(A[i])==m.end())
        m[A[i]]=i;
        else
        {
            if(2*A[i]==B)
            {
                int a = m[A[i]];
                int b = i;
            if(a<b)
            {
                if(p.first==-1)
                {
                    p={a,b};
                }
                if(p.second>b)
                {
                    p={a,b};
                }
            }
            }
        }
    }
    
    
    for(int i=0;i<A.size();i++)
    {
        if(m.find(B-A[i])!=m.end())
        {
            int a = i;
            int b = m[B-A[i]];
            if(a<b)
            {
                if(p.first==-1)
                {
                    p={a,b};
                }
                if(p.second>b)
                {
                    p={a,b};
                }
            }
        }
    }
    vector<int> v;
    if(p.first!=-1)
    {
        v.push_back(p.first+1);
        v.push_back(p.second+1);
        
    }
    return v;
}
