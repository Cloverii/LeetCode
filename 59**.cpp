class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> tmp(n, 0);
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) ans.push_back(tmp);
        int x = 0, y = -1, tot = 0, tm = -1;
        while(tot < n * n) {
            while(y + 1 < n && !ans[x][y + 1]) ans[x][++y] = ++tot;
            while(x + 1 < n && !ans[x + 1][y]) ans[++x][y] = ++tot;
            while(y > 0 && !ans[x][y - 1]) ans[x][--y] = ++tot;
            while(x > 0 && !ans[x - 1][y]) ans[--x][y] = ++tot;
        }
        return ans;
    }
};
