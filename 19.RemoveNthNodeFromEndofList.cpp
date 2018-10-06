/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {  
        ListNode h(-1);
        h.next = head;
        ListNode *p = &h;
        ListNode *q = &h;
        int i = 0;
        for (; q->next !=NULL, i<n; i++) {
            q = q->next;
        }
        while (q->next) {
            p = p->next;
            q = q->next;
        }
        
        p->next = p->next->next;
       
        return h.next;
    }
};