class Solution {
private:
    bool cat(const string &s, int i) {
        return i && (s[i - 1] == '1' || s[i - 1] == '2' && s[i] < '7');
    }
    
public:
    int numDecodings(string s) {
        if(s == "") return 0;
        vector<vector<int>> dp(2, vector<int>(s.size() + 1, 0));
        dp[0][0] = 1;
        /*
        int dp[2][s.size() + 1] = {1}; // undefined behavior
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < s.size() + 1; j++) {
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }*/
        //memset(dp, 0, sizeof(dp)); dp[0][0] = 1;
        for(int i = 1; i <= s.size(); ++i) {
            if(s[i - 1] != '0') 
                dp[0][i] = dp[0][i - 1] + dp[1][i - 1];
            dp[1][i] = cat(s, i - 1) ? dp[0][i - 1] : 0;
        }
        return dp[0][s.size()] + dp[1][s.size()];
        
    }
};
