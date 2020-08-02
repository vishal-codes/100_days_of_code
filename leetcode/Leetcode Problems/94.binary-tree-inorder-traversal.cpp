/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (63.18%)
 * Likes:    3266
 * Dislikes: 136
 * Total Accepted:    753.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,3,2]
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 * 
 */

// @lc code=start
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
        return ans;
          stack<TreeNode*> s;
        unordered_map<TreeNode*,int> m;
        s.push(root);
        m[root]++;
        while(!s.empty())
        {
            TreeNode* r = s.top();
            if(r->left!=NULL and m.find(r->left)==m.end())
            {
                s.push(r->left);
                m[r->left]++;
            }
            else
            {
                s.pop();
                // m.erase(r);
                ans.push_back(r->val);
                if(r->right!=NULL and m.find(r->right)==m.end())
                {
                    s.push(r->right);
                    m[r->right]++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

