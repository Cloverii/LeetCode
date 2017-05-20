class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        if(n < k) return ans;
        vector<int> tmp(k, 0);
        int i = 0;
        while(i >= 0 && tmp[0] <= n - k + 1) {
            tmp[i]++;
            if(tmp[i] > n) --i;
            else if(i == k - 1) ans.push_back(tmp);
            else tmp[++i] = tmp[i - 1];
        }
        return ans;
    }
    
    vector<vector<int>> combine1(int n, int k) {
        vector<vector<int>> ans;
        if(n < k) return ans;
        vector<int> tmp;
        backtrack(n, k, ans, tmp, 1);
        return ans;
    }
private:
    void backtrack(int n, int k, vector<vector<int>> &ans, vector<int> &tmp, int cur) {
        if(tmp.size() >= k) {
            ans.push_back(tmp);
            return;
        }
        for(int i = cur; i <= n; i++) {
            tmp.push_back(i);
            backtrack(n, k, ans, tmp, i + 1);
            tmp.pop_back();
        }
    }
};
