/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {

    if(A==NULL or A->next==NULL)
    {
        return A;
    }
    ListNode* d = deleteDuplicates(A->next);
    if(d->val==A->val)
    {
        A->next=d->next;
    }
    return A;
}
