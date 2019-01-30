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
    ListNode* rotateOnce(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* p = head;
        while (p->next->next != NULL) p = p->next;
        ListNode* q = p->next;
        p->next = NULL;
        q->next = head;
        return q;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        int n=0;
        ListNode* p = head;
        while (p!= NULL) {
            p = p->next;
            n++;
        }
        if (n == 0 || n == 1) return head;
        k = k % n;
        
        ListNode* res = head;
        while (k>0) {
            res = rotateOnce(res);
            k--;
        }
        return res;
    }
};