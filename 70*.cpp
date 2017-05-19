public class Solution {
    public int climbStairs(int n) {
        int dp0 = 1, dp1 = 1, ans = 1;
        for(int i = 2; i <= n; i++) {
            ans = dp0 + dp1;
            dp0 = dp1;
            dp1 = ans;
        }
        return ans;
    }
}
