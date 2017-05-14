class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size();
        int dp[n + 1][m + 1]; 
        memset(dp, 0x3f, sizeof(dp)); dp[0][1] = dp[1][0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
        /*for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }*/    
        return dp[n][m];
    }
};
