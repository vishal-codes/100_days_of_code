vector<int> Solution::lszero(vector<int> &A) {

    unordered_map<int,int> m;
    m[0]=0;
    int sum = 0;
    int ans = 0;
    int ans_index=0;
    int end_index=-1;
    for(int i=0;i<A.size();i++)
    {
        sum=sum+A[i];
        if(m.find(sum)!=m.end())
        {
            if((i-m[sum]+1)>ans)
            {
                ans = i-m[sum]+1;
                ans_index = m[sum];
                end_index = i;
            }
            
            
        }
        else
            m[sum]=i;
        
    }
    vector<int> v;
    for(int i = ans_index;i<=end_index;i++)
    v.push_back(A[i]);
    return v;
}
