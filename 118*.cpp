class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        if(numRows) ans[0].push_back(1);
        for(int i = 1; i < numRows; i++) {
            for(int j = 0; j < (i + 2 >> 1); j++)
                ans[i].push_back(ans[i - 1][j] + (j ? ans[i - 1][j - 1] : 0));
            for(int j = (i + 1 >> 1) - 1; j >= 0; j--)
                ans[i].push_back(ans[i][j]);
        }
        return ans;
    }
};
// 11 22 32 43 53 64
// 11 21 32 42 53 63
