class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        int row[n]; memset(row, -1, sizeof(row));
        dfs(ans, n, row, 0);
        return ans;
    }
    
private:
    void dfs(int& ans, int n, int* row, int depth) {
        if(depth == n) {
            ans++;
            return;
        }
        for(int i = 0; i < n; i++) {
            if(!check(depth, i, n, row)) continue;
            row[depth] = i;
            dfs(ans, n, row, depth + 1);
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
