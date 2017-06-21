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
    void __dfs(TreeNode* rt, int target, vector<vector<int>> &ans, vector<int> &tmp) {
        tmp.push_back(rt->val);
        if(!rt->left && !rt->right && target == rt->val) ans.push_back(tmp);
        if(rt->left) __dfs(rt->left, target - rt->val, ans, tmp);
        if(rt->right) __dfs(rt->right, target - rt->val, ans, tmp);
        tmp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root) return {};
        vector<vector<int>> ans;
        vector<int> tmp;
        __dfs(root, sum, ans, tmp);
        return ans;
    }
};
