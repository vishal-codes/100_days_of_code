/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {

   
    
    if(A==NULL)
    {
        vector<int> v;
        return v;
    }
    vector<int> a;
    a.push_back(A->val);
    vector<int> b = preorderTraversal(A->left);
    for(int i=0;i<b.size();i++)
    a.push_back(b[i]);
    b = preorderTraversal(A->right);
    for(int i=0;i<b.size();i++)
    a.push_back(b[i]);
    
    return a;

}
