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
    bool cmp(TreeNode *lft, TreeNode *rht) {
        if(lft && rht) {
            if(lft->val != rht->val) return false;
            return cmp(lft->left, rht->right) && cmp(lft->right, rht->left);
        }
        return !(lft || rht);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        /*
        return cmp(root->left, root->right);
        */
        queue<TreeNode *> q;
        q.push(root->left); q.push(root->right);
        while(q.size()) {
            TreeNode *lft = q.front(); q.pop();
            TreeNode *rht = q.front(); q.pop();
            if(lft && rht) {
                if(lft->val != rht->val) return false;
                q.push(lft->left);
                q.push(rht->right);
                q.push(lft->right);
                q.push(rht->left);
            } else if(lft || rht) return false;
        }
        return true;
    }
};
