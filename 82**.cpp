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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode header(-1), *curr = &header;
        header.next = head;
        bool flag = false;
        while(curr->next != NULL) {
            ListNode *nxt = curr->next;
            if(nxt->next != NULL && nxt->val == nxt->next->val) {
                curr->next = nxt->next;
                flag = true;
            } else {
                if(flag) {
                    curr->next = nxt->next;
                    flag = false;
                }
                else curr = curr->next;
            }
        }
        return header.next;
    }
};
