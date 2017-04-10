/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode header = new ListNode(-1);
        header.next = head;
        ListNode cur = header;
        int length = 0;
        while(cur.next != null) {
            ++length;
            cur = cur.next;
        }
        cur = header;
        int times = length / k;
        for(int i = 0; i < times; ++i)
            cur = reverse(cur, k);
        return header.next;
    }
    
    private ListNode reverse(ListNode header, int k) {
        ListNode cur = header.next, tmp; // cur = first valid node, insert from the second node
        int i = 0;
        while(++i < k) {
            //System.out.println(cur.val);
            tmp = cur.next;
            cur.next = tmp.next;
            tmp.next = header.next;
            header.next = tmp;
            //print(header, k);
        }
        return cur;
    }
    
    private void print(ListNode header, int k) {
        int i = 0;
        ListNode cur = header;
        while(i++ < k) {
            System.out.print(cur.next.val + "->");
            cur = cur.next;
        }
        System.out.println("");
    }
}
