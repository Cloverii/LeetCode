/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode header = new ListNode(-1);
        header.next = head;
        ListNode cur = header;
        ListNode first, second;
        while(cur.next != null && cur.next.next != null) {
            first = cur.next;
            second = first.next;
            cur.next = second;
            first.next = second.next;
            second.next = first;
            cur = first;
        }
        return header.next;
    }
}
