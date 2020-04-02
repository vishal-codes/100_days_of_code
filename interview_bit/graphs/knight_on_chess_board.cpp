bool isValid(int A,int B,int x,int y)
{
    if((x<A and x>=0) and (y<B and y>=0))
    return true;
    
    else
    return false;
}
int Solution::knight(int A, int B, int C, int Y, int E, int F) {
    bool v[A][B];
    C=C-1;
    Y=Y-1;
    E=E-1;
    F=F-1;
    set<pair<int,pair<int,int>>> s;
    s.insert({0,{C,Y}});
    for(int i=0;i<A;i++)
    {
        for(int j=0;j<B;j++)
        {
            v[i][j]=false;
        }
    }
    while(!s.empty())
    {
        pair<int,pair<int,int>> p = *(s.begin());
        s.erase(s.begin());
        int d = p.first;
        pair<int,int> c = p.second;
        v[c.first][c.second]=true;
        if(c.first==E and c.second==F)
        {
            return d;
        }
        C=c.first;
        Y=c.second;
        if(isValid(A,B,C+2,Y-1) and !v[C+2][Y-1] ){s.insert({d+1,{C+2,Y-1}});}
        if(isValid(A,B,C+2,Y+1) and !v[C+2][Y+1] ){s.insert({d+1,{C+2,Y+1}});}
        if(isValid(A,B,C-2,Y-1) and !v[C-2][Y-1] ){s.insert({d+1,{C-2,Y-1}});}
        if(isValid(A,B,C-2,Y+1) and !v[C-2][Y+1] ){s.insert({d+1,{C-2,Y+1}});}
        if(isValid(A,B,C+1,Y-2) and !v[C+1][Y-2] ){s.insert({d+1,{C+1,Y-2}});}
        if(isValid(A,B,C+1,Y+2) and !v[C+1][Y+2] ){s.insert({d+1,{C+1,Y+2}});}
        if(isValid(A,B,C-1,Y-2) and !v[C-1][Y-2] ){s.insert({d+1,{C-1,Y-2}});}
        if(isValid(A,B,C-1,Y+2) and !v[C-1][Y+2] ){s.insert({d+1,{C-1,Y+2}});}
        
        
    
        
    }
    return -1;
}
