/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool helper(TreeNode* A,int min,int max)
{
    if(A==NULL)
    {
        return true;
    }
    if(A->val<=min or A->val>=max)
    {
        return false;
    }
    
    return helper(A->left,min,A->val) and helper(A->right,A->val,max);
}
int Solution::isValidBST(TreeNode* A) {
    return helper(A,INT_MIN,INT_MAX);
}
