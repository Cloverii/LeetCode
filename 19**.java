/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) { // Without header
        ListNode header = new ListNode(-1); // necessary, or RE
        header.next = head;
        ListNode first = header, nth = header;
        for(int i = 0; i < n; i++) {
            nth = nth.next;
        }
        while(nth.next != null) {
            nth = nth.next;
            first = first.next;
        }
        first.next = first.next.next;
        return header.next;
    }
}
