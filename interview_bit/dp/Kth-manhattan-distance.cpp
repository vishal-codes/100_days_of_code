vector<vector<int> > Solution::solve(int K, vector<vector<int> > &B) {
    
    int m = B.size();
    
    if(m<=0)
    {
        vector<vector<int>> v;
        return v;
    }
    if(K==0)
    {
        return B;
    }
    int n = B[0].size();
    vector<vector<int>> v1(m,vector<int>(n,0));
    vector<vector<int>> v2(m,vector<int>(n,0));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            v1[i][j]=B[i][j];
        }
    }
    
    for(int k=0;k<K;k++)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(k%2==0){
                int c = v1[i][j];
                if(i+1<m)
                {
                    c=max(c,v1[i+1][j]);
                }
                if(i-1>=0)
                {
                    c=max(c,v1[i-1][j]);
                }
                if(j+1<n)
                {
                    c=max(c,v1[i][j+1]);
                }
                if(j-1>=0)
                {
                    c=max(c,v1[i][j-1]);
                }
                v2[i][j]=c;}
                
                else
                {
                    
                int c = v2[i][j];
                if(i+1<m)
                {
                    c=max(c,v2[i+1][j]);
                }
                if(i-1>=0)
                {
                    c=max(c,v2[i-1][j]);
                }
                if(j+1<n)
                {
                    c=max(c,v2[i][j+1]);
                }
                if(j-1>=0)
                {
                    c=max(c,v2[i][j-1]);
                }
                v1[i][j]=c;
                }
                
            }
        }
    }
    if(K%2)
    {
        return v2;
    }
    return v1;
}
