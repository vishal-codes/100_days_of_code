/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode* root,long min,long max)
    {
        if(root==NULL)
        {
            return true;
        }
        int v = root->val;
        if(v<=min or v>=max)
        {
            return false;
        }
        return helper(root->left,min,v) and helper(root->right,v,max);
    }
    bool isValidBST(TreeNode* root) {
       
        return helper(root,LONG_MIN,LONG_MAX);
    }
};