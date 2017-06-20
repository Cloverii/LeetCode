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
    TreeNode *__help(TreeNode *rt) {  // return the last node after flatten
        if(rt == NULL) return rt;
        if(!rt->left && !rt->right) return rt;
        TreeNode *ret1 = __help(rt->left), *ret2 = __help(rt->right);
        if(ret1) {
            TreeNode *tmp = rt->right;
            rt->right = rt->left;
            rt->left = NULL;
            ret1->right = tmp;
        }
        return ret2 ? ret2 : ret1;
    }
public:
    void flatten(TreeNode* root) {
        if(root) __help(root);
    }
};
