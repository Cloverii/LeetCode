class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far = 0;
        for(int i = 0; i < nums.size() && i <= far; i++) {
            far = max(far, i + nums[i]);
        }
        return far >= nums.size() - 1;
    }
};

/*class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool dp[nums.size() + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(dp[i]) for(int j = 1; j <= nums[i] && j + i < nums.size(); j++) {
                dp[j + i] = 1;
            }
        }
        return dp[nums.size() - 1];
    }
};*/
