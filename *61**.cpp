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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        /*ListNode *header = new ListNode(0); header->next = head;
        ListNode *fst = header, *scd = header;
        int length = 0;
        for( ; fst->next != NULL; fst = fst->next)
            length++;
        fst = header;
        k %= length;
        for(int i = 0; i < k; i++)
            scd = scd->next;
        if(scd != fst) {
            while(scd->next != NULL) {
                scd = scd->next;
                fst = fst->next;
            }
            header->next = fst->next;
            fst->next = scd->next;
            scd->next = head;
        }
        return header->next;*/
        ListNode *tail = head;
        int n = 1;
        for( ; tail->next != NULL; tail = tail->next) 
            n++;
        k = n - k % n; // (n - k % n) % n
        tail->next = head;
        for(int i = 0; i < k; i++) {
            head = head->next;
            tail = tail->next;
        }
        tail->next = NULL;
        return head;
    }
};
