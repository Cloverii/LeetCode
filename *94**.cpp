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
    void helper(TreeNode *root, vector<int> &ans) {
        if(root == NULL) return;
        if(root->left != NULL) helper(root->left, ans);
        ans.push_back(root->val);
        if(root->right != NULL) helper(root->right, ans);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        /*helper(root, ans);*/
        stack<TreeNode*> st;
        TreeNode *cur = root;
        while(cur != NULL || st.size()) {
            if(cur != NULL) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top(); st.pop();
                ans.push_back(cur->val);
                cur = cur->right;
            }
        }
        return ans;
    }
};
