/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode ans = new ListNode(0);
        ListNode pre = ans;
        while(l1 != null && l2 != null) {
            if(l1.val < l2.val) {
                pre.next = l1; l1 = l1.next;
            } else {
                pre.next = l2; l2 = l2.next;
            }
            pre = pre.next;
        }
        while(l1 != null) { // or if(l1 != null) pre.next = l1;
            pre.next = l1; pre = l1;
            l1 = l1.next;            
        }
        while(l2 != null) {
            pre.next = l2; pre = l2;
            l2 = l2.next;            
        }        
        return ans.next;
    }
}
