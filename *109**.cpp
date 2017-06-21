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
    ListNode *cur;
    TreeNode* __dfs(ListNode *head, ListNode *tail) {
        if(head == tail) return NULL;
        ListNode *slow = head, *fast = head, *pre = head;
        while(fast != tail && fast->next != tail) {
            //cout << "bug" << endl;
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *rt = new TreeNode(slow->val);
        rt->left = __dfs(head, slow);
        rt->right = __dfs(slow->next, tail);
        return rt;
    }
    
    int __size(ListNode *head) {
        int sz = 0;
        while(head) {
            sz++;
            head = head->next;
        }
        return sz;
    }
    
    TreeNode *__inOrder(int n) {
        if(!n) return NULL;
        TreeNode *rt = new TreeNode(-1);
        rt->left = __inOrder(n / 2);
        rt->val = cur->val;
        cur = cur->next;
        rt->right = __inOrder(n - n / 2 - 1);
        return rt;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        /*
        return __dfs(head, NULL);
        */
        // the sorted linked list is an in-order traverse,
        // so just in order traverse
        // and there may be more than one answer
        cur = head;
        return __inOrder(__size(cur));
    }
};
