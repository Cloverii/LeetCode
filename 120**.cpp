class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.size() + 1, 0);
        for(int cur = triangle.size() - 1; cur >= 0; cur--) {
            for(int j = 0; j <= cur; j++)
                dp[j] = triangle[cur][j] + min(dp[j], dp[j + 1]);
            //for(int j = 0; j <= cur; j++) cout << dp[i][j] << ' '; cout << endl;
        }
        return dp[0];
    }
};
