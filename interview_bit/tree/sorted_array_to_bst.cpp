×
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* helper(const vector<int> &A,int s,int e)
{
    if(s>e)
    {
        return NULL;
    }
    int m = (s+e)/2;
    TreeNode* root = new TreeNode(A[m]);
    root->left = helper(A,s,m-1);
    root->right = helper(A,m+1,e);
    return root;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    
    return helper(A,0,A.size()-1);
}