class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> tmp;
        string s(n, '.');
        for(int i = 0; i < n; i++) tmp.push_back(s);
        int row[n]; memset(row, -1, sizeof(row));
        dfs(ans, tmp, n, row, 0);
        return ans;
    }
    
    void dfs(vector<vector<string>>& ans, vector<string>& tmp, int n, int* row, int depth) {
        if(depth == n) {
            ans.push_back(tmp);
            return;
        }
        for(int i = 0; i < n; i++) {
            if(!check(depth, i, n, row)) continue;
            row[depth] = i;
            tmp[depth][i] = 'Q';
            dfs(ans, tmp, n, row, depth + 1);
            tmp[depth][i] = '.';
            row[depth] = -1;
        }
    }
    
    bool check(int x, int y, int n, int* row) {
        for(int i = 0; i < n; i++) {
            if(~row[i]) {
                if( y == row[i] || x + y == row[i] + i || x - y == i - row[i])
                    return false;
            }
        }
        return true;
    }
};
