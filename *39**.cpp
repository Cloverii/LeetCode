class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        helper(candidates, ans, tmp, 0, target);
        return ans;
    }
private:    
    void helper(vector<int>& v, vector<vector<int>> &ans, vector<int>& tmp, int id, int target) {
        if(target == 0) {
            ans.push_back(tmp);
            return;
        }
        for(int i = id; i < v.size(); i++) {
            int cur = v[i];
            if(target >= cur) {
                tmp.push_back(cur);
                helper(v, ans, tmp, i, target - cur);
                tmp.pop_back();
            }
        }
    }
};
