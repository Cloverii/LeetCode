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
    vector<vector<int>> levelOrder(TreeNode* root) {
        /*
        vector<vector<int>> ans;
        __dfs(root, 0, ans);
        return ans;
        */
        
        if(root == NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            int n = q.size();
            vector<int> v;
            while(n--) {
                TreeNode *cur = q.front(); q.pop();
                //if(cur->val == 20) cout << "bug" << endl;
                v.push_back(cur->val);
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
