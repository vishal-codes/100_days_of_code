vector<int> Solution::nextGreater(vector<int> &A) {

    stack<int> s;
    int n = A.size();
    vector<int> ans(n);
    
    for(int i=n-1;i>=0;i--)
    {
        while(!s.empty() and s.top()<=A[i])
        {
            s.pop();
        }
        if(s.empty())
        {
            ans[i]=-1;
        }
        else
        {
            ans[i]=s.top();
        }
        s.push(A[i]);
    }
    return ans;
    
}
