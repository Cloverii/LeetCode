class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
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
        if(id >= v.size()) return;
        for(int i = id; i < v.size(); i++) {
            int cur = v[i];
            if(i > id && v[i] == v[i - 1]) continue; // the same layer
            if(target >= cur) {
                tmp.push_back(cur);
                helper(v, ans, tmp, i + 1, target - cur);
                tmp.pop_back();
            }
        }
    }
};
