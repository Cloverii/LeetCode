class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tmp;
        vector<int> flag(8, 0);
        vector<vector<int>> ans;
        dfs(nums, ans, tmp, flag, 0);
        return ans;
    }
private:
    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& tmp, vector<int>& flag, int id) {
        if(id == nums.size()) {
            ans.push_back(tmp);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(!flag[i]) {
                tmp.push_back(nums[i]);
                flag[i] = 1;
                dfs(nums, ans, tmp, flag, id + 1);
                flag[i] = 0;
                tmp.pop_back();
            }
        }
    }
};
