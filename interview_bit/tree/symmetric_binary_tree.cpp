
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int helper(TreeNode* t1,TreeNode* t2)
{
    if(t1==NULL and t2==NULL)
    {
        return 1;
    }
    if(t1==NULL or t2==NULL)
    {
        return 0;
    }
    if(t1->val!=t2->val) return false;
    
    return helper(t1->left,t2->right) and helper(t1->right,t2->left);
}
int Solution::isSymmetric(TreeNode* A) {
    if(A==NULL)
    {
        return 1;
    }
    return helper(A->left,A->right);
}
Blog