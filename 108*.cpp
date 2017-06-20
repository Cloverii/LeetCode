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
    TreeNode* __build(const vector<int> &nums, int l, int r) {
        if(r - l < 1) return NULL;
        int mid = l + (r - l) / 2;
        TreeNode * rt = new TreeNode(nums[mid]);
        rt->left = __build(nums, l, mid);
        rt->right = __build(nums, mid + 1, r);
        return rt;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return __build(nums, 0, nums.size());
    }
};
