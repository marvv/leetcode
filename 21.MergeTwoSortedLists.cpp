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
    void addNode(ListNode*& node, ListNode* & head, ListNode*& tail)
    {
        if (!head) 
        {
            head = tail = node;
        }
        else 
        {
            tail->next = node;
            tail = node;
        }
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        ListNode* p = l1;
        ListNode* q= l2;
        ListNode* tmp = NULL;
        while (p && q)
        {
            if (p->val <= q->val)
            {
                tmp = p;
                p = p->next;
                addNode(tmp, head, tail);
                
            }
            else
            {
                tmp = q;
                q = q->next;
                addNode(tmp, head, tail);
            }     
        }
        
        while (p)
        {
            tmp = p;
            p = p->next;
            addNode(tmp, head, tail);
        }
        
        while (q)
        {
            tmp = q;
            q = q->next;
            addNode(tmp, head, tail);   
        }
        
        return head;
    }
};