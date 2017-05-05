class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp[nums.size() + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < nums.size(); i++) {
            dp[i] = nums[i];
            if(i) {
                if(dp[i - 1] > 0) dp[i] += dp[i - 1];
            }
        }
        return *max_element(dp, dp + nums.size());
    }
};
