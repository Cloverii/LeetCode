/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* __dfs(ListNode *head, ListNode *tail) {
        if(head == tail) return NULL;
        ListNode *slow = head, *fast = head, *pre = head;
        while(fast != tail && fast->next != tail) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *rt = new TreeNode(slow->val);
        rt->left = __dfs(head, slow);
        rt->right = __dfs(slow->next, tail);
        return rt;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return __dfs(head, NULL);
    }
};
