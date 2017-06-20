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
    void __dfs(TreeNode *rt, int depth, vector<vector<int>> &ans) {
        if(rt == NULL) return;
        while(ans.size() <= depth) ans.push_back({});
        ans[depth].push_back(rt->val);
        __dfs(rt->left, depth + 1, ans);
        __dfs(rt->right, depth + 1, ans);
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        __dfs(root, 0, ans);
        //return vector<vector<int>> (ans.rbegin(), ans.rend());
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
