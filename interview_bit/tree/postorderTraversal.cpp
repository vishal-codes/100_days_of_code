/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    
    if(A==NULL)
    {
        vector<int> v;
        return v;
    }
    vector<int> a = postorderTraversal(A->left);
    vector<int> b = postorderTraversal(A->right);
    for(int i=0;i<b.size();i++)
    a.push_back(b[i]);
    a.push_back(A->val);
    return a;
}
