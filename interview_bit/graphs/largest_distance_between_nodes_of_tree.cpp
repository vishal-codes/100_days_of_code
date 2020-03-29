class tree
{
    public:
    int val;
    vector<tree*> child;
    
    tree(int val)
    {
        this->val = val;
        
    }
};
void insert(tree* root,int data)
{
    
    if(root->val==data)
    {
        root->child.push_back(new tree(data));
        return;
        
    }
    for(int i=0;i<root->child.size();i++)
    {
        insert(root->child[i],data);
    }
}
int height(tree* root)
{
    if(root->child.size()==0)
    {
        return 0;
    }
    int h = 0;
    for(int i=0;i<root->child.size();i++)
    {
        h = max(h,height(root->child[i]));
    }
    return h+1;
}
int diameter(tree* root,int &ans)
{
    if(root->child.size()==0)
    {
        return 0;
    }
    vector<int> v;
    
   vector<tree* > c = root->child;
    // mx -> highest value
    // mn -> second highest value
    int mx = 0, mn = 0;
    // Loop for each child
    for (int i = 0; i < c.size(); i++) {
        int val = 1 + diameter(c[i], ans);
        if (val > mx) {
            mn = max(mx, mn);
            mx = val;
        } else if (val > mn) {
            mn = val;
        }
    }
    // Update ans
    ans = max(ans, mx + mn);
    return mx;
    
    
}
int Solution::solve(vector<int> &A) {
    
    int n = A.size();
    vector<tree*> v(n);
    
    for(int i=0;i<n;i++)
    v[i]=new tree(i);
    
    tree* root = NULL;
    
    for(int i=0;i<n;i++)
    {
        if(A[i]==-1)
        {
            root=v[i];
            continue;
        }
        (v[A[i]]->child).push_back(v[i]);
    }
    int ans = 0;
    diameter(root,ans);
    return ans;
    
}
