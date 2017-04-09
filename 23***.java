/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode head = new ListNode(-1), cur = head;
        if(lists.length == 0) return null;
        PriorityQueue<ListNode> q = new PriorityQueue(lists.length, new Comparator<ListNode>(){
            @Override
            public int compare(ListNode o1,ListNode o2){
                return Integer.compare(o1.val, o2.val); // to simplify code
            }
        });
        
        for(ListNode node: lists) {
            if(node != null) q.add(node); // pq doesn't permit null elements
        }
        
        while(!q.isEmpty()) {
            ListNode node = q.poll();
            //if(node == null) continue; // unnecessary
            if(node.next != null) q.add(node.next);
            cur.next = node;
            cur = node;
            //cur.next = null; // unnecessary
            
        }
        return head.next;
    }
}
