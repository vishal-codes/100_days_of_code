/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;1
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* helper(Node* node,unordered_map<int,Node*>& m)
    {
        if(m.find(node->val)!=m.end())
        {
            return m[node->val];
        }
        Node* newNode = new Node(node->val);
        m[node->val]=newNode;
        for(int i=0;i<node->neighbors.size();i++)
        {
            newNode->neighbors.push_back(helper(node->neighbors[i],m));
        }
        return newNode;
    }
    Node* cloneGraph(Node* node) {
         if(node==NULL)
         return NULL;
          unordered_map<int,Node*> m;
          return helper(node,m);
    }
};
// @lc code=end

