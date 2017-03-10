class Solution {
public:
    string longestPalindrome(string s) {
        int l = s.size(), ans = 1, st = 0;
        int dp[l + 5][l + 5];
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < l; i++) 
            dp[i][i] = 1, dp[i + 1][i] = 0; //[i+1][i]
        for(int k = 2; k <= l; k++)
            for(int i = 0; i <= l - k; i++) {
                int j = i + k - 1;
                if(s[i] == s[j]) {
                    if(~dp[i + 1][j - 1]) {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                        if(dp[i][j] > ans)
                            ans = dp[i][j], st = i;
                    }
                }
            }
        return s.substr(st, ans);
    }
};
