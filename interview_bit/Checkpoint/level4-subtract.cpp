/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* midpoint(ListNode* node)
{
    if(node==NULL)
    {
        return NULL;
    }
    ListNode *s = node;
    ListNode *f = node;
    
    while(f!=NULL)
    {
        
            f=f->next;
    
        if(f!=NULL){
        
        s=s->next;
        f=f->next;
        }
    }
    return s;
    
}
ListNode* Solution::subtract(ListNode* A) {
    
    vector<int> v;
    
    ListNode* l = midpoint(A);
    ListNode* m = l;
    while(l!=NULL)
    {
        v.push_back(l->val);
        l=l->next;
    }
    
    int n = v.size();
    ListNode* head=A;
    int i = n-1;
    while(head!=m)
    {
        head->val = v[i]-head->val;
        head=head->next;
        i--;
    }
    return A;
}
