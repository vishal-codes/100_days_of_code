/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inorder(TreeNode* root,vector<int> &A)
{
    if(root==NULL) return;
    inorder(root->left,A);
    A.push_back(root->val);
    inorder(root->right,A);
}
int Solution::t2Sum(TreeNode* root, int B) {
    vector<int> v;
    inorder(root,v);
    int i = 0;
    int j = v.size()-1;
    while(i<j)
    {
        int sum = v[i]+v[j];
        if(sum==B)
        {
            return 1;
        }
        if(sum<B)
        {
            i++;
        }
        else
            j--;
    }
    return 0;
}
