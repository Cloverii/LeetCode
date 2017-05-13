class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        m--, n--;
        for(int i = 0; i <= n; i++) dp[0][i] = 1;
        for(int i = 1; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                dp[i][j] = 0;
                for(int k = 0; k <= j; k++) {
                    dp[i][j] += dp[i - 1][k];
                }
            }
        }
        return dp[m][n];
    }
};
