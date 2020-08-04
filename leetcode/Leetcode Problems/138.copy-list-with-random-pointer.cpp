/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 *
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (36.16%)
 * Likes:    3413
 * Dislikes: 678
 * Total Accepted:    422.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[7,null],[13,0],[11,4],[10,2],[1,0]]'
 *
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 * 
 * Return a deep copy of the list.
 * 
 * The Linked List is represented in the input/output as a list of n nodes.
 * Each node is represented as a pair of [val, random_index] where:
 * 
 * 
 * val: an integer representing Node.val
 * random_index: the index of the node (range from 0 to n-1) where random
 * pointer points to, or null if it does not point to any node.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [[1,1],[2,1]]
 * Output: [[1,1],[2,1]]
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: head = [[3,null],[3,0],[3,null]]
 * Output: [[3,null],[3,0],[3,null]]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: head = []
 * Output: []
 * Explanation: Given linked list is empty (null pointer), so return null.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -10000 <= Node.val <= 10000
 * Node.random is null or pointing to a node in the linked list.
 * Number of Nodes will not exceed 1000.
 * 
 * 
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head==NULL)
            return NULL;
        unordered_map<Node*,int> m;
        vector<Node*> v;


        Node* c1 = head;
        m[c1]=0;

        Node* c2 = new Node(head->val);
        Node* head2 = c2;
        
        
        c1 = c1->next;
        v.push_back(c2);
        int i =1;
        
        while(c1!=NULL)
        {
            m[c1]=i;
            c2->next = new Node(c1->val);
            c2=c2->next;
            v.push_back(c2);
            i++;
            c1=c1->next;
        }
        c2=head2;
        while(head!=NULL)
        {
            if(head->random!=NULL)
            {
                head2->random=v[m[head->random]];
            }
            head2=head2->next;
            head = head->next;
        }
        return c2;
    }
};
// @lc code=end

