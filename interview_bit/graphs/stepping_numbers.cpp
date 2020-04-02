#define pb push_back
vector<int> Solution::stepnum(int A, int B) {
    vector<int> ans;
    if(A<=0)
    {
        ans.pb(0);
    }
    
    queue<int> q;
    
    for(int i=1;i<=9;i++)
        q.push(i);
        
    while(q.front()<=B)
    {
        int num = q.front();
        q.pop();
        if(num>=A)
        ans.pb(num);
        int l = num%10;
        if(l>0) q.push(num*10+(l-1));
        if(l<9) q.push(num*10+(l+1));
    }
    return ans;
}
