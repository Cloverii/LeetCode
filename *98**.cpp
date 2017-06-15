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
    bool helper(TreeNode *root, TreeNode *maxx, TreeNode *minn) {
        if(!root) return true;
        if(maxx && root->val >= maxx->val) return false;
        if(minn && root->val <= minn->val) return false;
        return helper(root->left, root, minn) && helper(root->right, maxx, root);
    }
public:
    bool isValidBST(TreeNode *root) {
        return helper(root, NULL, NULL);
    }
};
