/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    void move(ListNode *tar, ListNode *src) {
        if(tar == src) return;
        ListNode *tmp = src->next;
        src->next = tmp->next;
        tmp->next = tar->next;
        tar->next = tmp;
    }
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *less = new ListNode(-1), *greater = new ListNode(-1);
        ListNode *header = new ListNode(-1); header->next = head;
        ListNode *i = less, *j = greater, *cur = header;
        while(header->next != NULL) {
            if(header->next->val < x) {
                move(i, header);
                i = i->next;
            } else {
                move(j, header);
                j = j->next;
            }
        }
        i->next = greater->next;
        ListNode *ans = less->next;
        delete less; delete greater; delete header;
        return ans;
    }
};
