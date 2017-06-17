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
    TreeNode* helper(vector<int>& pre, vector<int>& in, int l1, int r1, int l2, int r2) {
        if(l1 == r1 || l2 == r2) return NULL;
        TreeNode *rt = new TreeNode(pre[l1]);
        int id = find(in.begin() + l2, in.begin() + r2, pre[l1]) - in.begin() - l2;
        //cout << id << endl;
        rt->left = helper(pre, in, l1 + 1, l1 + 1 + id, l2, l2 + id);
        rt->right = helper(pre, in, l1 + 1 + id, r1, l2 + id + 1, r2);
        return rt;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, preorder.size(), 0, preorder.size());
    }
};
