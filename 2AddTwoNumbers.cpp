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
    void addNumber(ListNode*&head, ListNode*& tail, int number)
    {
        ListNode* p  = new ListNode(number);
        if (tail == NULL) 
        {
            tail = p;
        }
        else
        {
            tail->next = p;
            tail = p;
        }
        
        if (head == NULL) head = tail;
    }
    
    void calc(int& result, int& extra)
    {
       if (result >= 10) 
        {
            extra = 1;
            result = result - 10;
        }
        else
        {
            extra = 0;
        }
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* result = NULL;
        ListNode* tail = NULL;
        int extra = 0;
        int tmp = 0;
        while (p != NULL && q != NULL)
        {
            tmp = p->val + q->val + extra;
            calc(tmp, extra);
            addNumber(result, tail, tmp);    
            p = p->next;
            q = q->next;
        }
        
        while (p!= NULL)
        {
            tmp = p->val + extra;
            calc(tmp, extra);
            addNumber(result, tail, tmp); 
            p = p->next;
        }
        
        while (q != NULL)
        {
            tmp = q->val + extra;
            calc(tmp, extra);
            addNumber(result, tail, tmp); 
            q = q->next;
        }
        
        if (extra)
        {
            addNumber(result, tail, 1);
        }
        
        return result;
    }
};