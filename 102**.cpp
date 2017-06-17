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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        map<TreeNode*, int> mp;
        vector<TreeNode*> v;
        mp[root] = 0;
        q.push(root);
        while(q.size()) {
            TreeNode *cur = q.front(); q.pop();
            //if(cur->val == 20) cout << "bug" << endl;
            if(v.size() && mp[cur] != mp[v[0]]) {
                vector<int> tmp;
                for(auto node: v)
                    tmp.push_back(node->val);
                v.clear();
                ans.push_back(tmp);
            }
            v.push_back(cur);
            if(cur->left) {
                q.push(cur->left);
                mp[cur->left] = mp[cur] + 1;
            }
            if(cur->right) {
                q.push(cur->right);
                mp[cur->right] = mp[cur] + 1;
            }
            
        }
        if(v.size()) {
            vector<int> tmp;
            for(auto node: v)
                tmp.push_back(node->val);
            ans.push_back(tmp);
        }
        return ans;
    }
};
