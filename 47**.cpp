class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // need sort
        vector<int> tmp;
        vector<int> flag(8, 0);
        vector<vector<int>> ans;
        dfs(nums, ans, tmp, flag);
        return ans;
    }
private:
    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& tmp, vector<int>& flag) {
        if(tmp.size() == nums.size()) {
            ans.push_back(tmp);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(i && !flag[i - 1] && nums[i - 1] == nums[i]) continue; // arrange the order
            if(!flag[i]) {
                tmp.push_back(nums[i]);
                flag[i] = 1;
                dfs(nums, ans, tmp, flag);
                flag[i] = 0;
                tmp.pop_back();
            }
        }
    }
};
