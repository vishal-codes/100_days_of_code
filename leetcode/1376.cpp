class node
{
    public:
    int val;
    int time;
    vector<node*> c;
    
    node(int val,int time)
    {
        this->val=val;
        this->time=time;
    }
    
    
};
int minutes(node* root)
{
    if(root->c.size()==0)
    {
        return 0;
    }
    int m = INT_MIN;
    for(int i=0;i<root->c.size();i++)
    {
        int a = minutes(root->c[i]);
        m = max(a,m);
    }
    m = m + root->time;
    return m;
}
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<node*> nodes;
        for(int i=0;i<n;i++)
        {
            nodes.push_back(new node(i,informTime[i]));
            
        }
        node* root = nodes[headID];
        for(int i=0;i<n;i++)
        {
            if(manager[i]!=-1)
            {
                nodes[manager[i]]->c.push_back(nodes[i]);
            }
        }
        return minutes(root);
    }
};