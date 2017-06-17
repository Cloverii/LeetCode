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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode header(-1), *curr = &header;
        header.next = head;
        for(int i = 0; i < m - 1; i++) {
            curr = curr->next;
        }
        ListNode *pre = curr;
        curr = curr->next;
        n -= m;
        for(int i = 0; i < n; i++) {
            ListNode *tmp = pre->next;
            pre->next = curr->next;
            curr->next = pre->next->next;
            pre->next->next = tmp;
            //curr = pre->next;
            
        }
        return header.next;
    }
};
