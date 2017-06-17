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
    TreeNode *helper(vector<int> &in, vector<int> &post, int l1, int r1, int l2, int r2) {
        if(l1 == r1 || l2 == r2) return NULL;
        TreeNode *rt = new TreeNode(post[r2 - 1]);
        int id = find(in.begin() + l1, in.begin() + r1, post[r2 - 1]) - in.begin() - l1;
        rt->left = helper(in, post, l1, l1 + id, l2, l2 + id);
        rt->right = helper(in, post, l1 + id + 1, r1, l2 + id, r2 - 1);
        return rt;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, postorder, 0, inorder.size(), 0, postorder.size());
    }
};
