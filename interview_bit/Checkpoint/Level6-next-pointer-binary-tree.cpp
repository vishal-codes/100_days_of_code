/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    
    queue<TreeLinkNode*> q1;
    queue<TreeLinkNode*> q2;
    q1.push(A);
    while(q1.empty()==false or q2.empty()==false)
    {
        while(!q1.empty())
        {
            TreeLinkNode* t = q1.front();
            q1.pop();
            
            if(!q1.empty())
            {
                t->next=q1.front();
            }
            if(t->left!=NULL)
            q2.push(t->left);
            
            if(t->right!=NULL)
            q2.push(t->right);
            
        }
        
        while(!q2.empty())
        {
            TreeLinkNode* t = q2.front();
            q2.pop();
            
            if(!q2.empty())
            {
                t->next=q2.front();
            }
            
            if(t->left!=NULL)
            q1.push(t->left);
            
            if(t->right!=NULL)
            q1.push(t->right);
            
        }
    }
}
