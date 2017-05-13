class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0) return 0;
        int n = obstacleGrid[0].size();
        int dp[m + 1][n + 1], last;
        memset(dp, 0, sizeof(dp)); dp[1][0] = 1; // or dp[0][1] = 1;
        /*for(int i = 1; i <= m; i++) { // O(n^3)
            last = 1;
            for(int j = 1; j <= n; j++) {
                if(obstacleGrid[i - 1][j - 1]) last = j + 1;
                dp[i][j] = 0;
                if(!obstacleGrid[i - 1][j - 1]) for(int k = last; k <= j; k++) {
                    dp[i][j] += dp[i - 1][k];
                }
            }
        }*/
        for(int i = 1; i <= m; i++) // O(n^2)
            for(int j = 1; j <= n; j++) {
                if(!obstacleGrid[i - 1][j - 1]) 
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
        /*for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }*/
        return dp[m][n];
    }
};
