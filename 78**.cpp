class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        backtrack(ans, tmp, 0, nums);
        return ans;
    }
private:
    void backtrack(vector<vector<int>> &ans, vector<int> &tmp, int cur, vector<int> &nums) {
        ans.push_back(tmp);
        if(cur == nums.size()) {
            return;
        }
        for(int i = cur; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            backtrack(ans, tmp, i + 1, nums);
            tmp.pop_back();
        }
    }
};
