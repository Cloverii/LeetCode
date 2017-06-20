/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        queue<TreeLinkNode *> q;
        q.push(root);
        while(q.size()) {
            int n = q.size();
            vector<TreeLinkNode *> v;
            while(n--) {
                TreeLinkNode *cur = q.front(); q.pop();
                v.push_back(cur);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            for(int i = 0; i < v.size() - 1; i++) {
                v[i]->next = v[i + 1];
            }
        }
    }
};
