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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *ans = new ListNode(-1);
        ListNode *curr = ans;
        while(l1 != NULL || l2 != NULL) {
            int tmp = carry;
            if(l1 != NULL) {
                tmp += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL) {
                tmp += l2->val;
                l2 = l2->next;
            }
            curr->next = new ListNode(tmp % 10);
            curr = curr->next;
            carry = tmp / 10;
            //l1 = l1->next, l2 = l2->next; //RE
        }
        if(carry) { //***
            curr->next = new ListNode(carry);
        }
        return ans->next;
    }
};
