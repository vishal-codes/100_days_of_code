/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    queue<TreeNode*> q1,q2;
    q1.push(A);
    vector<vector<int>> ans;
    
    
    while(1)
    {
    vector<int> v;
    while(!q1.empty())
    {
        TreeNode* temp = q1.front();
        q1.pop();
        v.push_back(temp->val);
        if(temp->left)
        q2.push(temp->left);
        if(temp->right)
        q2.push(temp->right);
        
    }
    if(v.size()>0)
    {
        ans.push_back(v);
        v.clear();
    }
    else
    {
        break;
    }
    while(!q2.empty())
    {
        TreeNode* temp = q2.front();
        q2.pop();
        v.push_back(temp->val);
        if(temp->left)
        q1.push(temp->left);
        if(temp->right)
        q1.push(temp->right);
        
    }
        if(v.size()>0)
    {
        ans.push_back(v);
        v.clear();
    }
    else
    {
        break;
    }
    }
    return ans;
}
