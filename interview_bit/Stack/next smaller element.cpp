vector<int> Solution::prevSmaller(vector<int> &A) {

    vector<int> ans(A.size());
    stack<int> s;
    for(int i=0;i<ans.size();i++)
    {
        while(!s.empty() and s.top()>=A[i])
        {
            s.pop();
        }
        if(s.empty())
        {
            ans[i]=-1;
        }
        else
            ans[i]=s.top();
            
        s.push(A[i]);
    }
    return ans;
}
