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
    vector<TreeNode*> helper(int st, int ed) {
        if(st > ed) {
            return {NULL};
        }
        vector<TreeNode*> ans;
        for(int i = st; i <= ed; ++i) {
            vector<TreeNode*> lftSon = helper(st, i - 1);
            vector<TreeNode*> rhtSon = helper(i + 1, ed);
            for(auto lft: lftSon) {
                for(auto rht: rhtSon) {
                    TreeNode *rt = new TreeNode(i);
                    rt->left = lft;
                    rt->right = rht;
                    ans.push_back(rt);
                }
            }
        }
        return ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return helper(1, n);
    }
};
