public class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] ans = new int[2];
        ans[0] = lowerBound(nums, 0, nums.length, target);
        ans[1] = upperBound(nums, 0, nums.length, target) - 1;
        if(ans[0] > ans[1]) ans[0] = ans[1] = -1;
        return ans;
    }
    private int upperBound(int[] nums, int l, int r, int target) {
        while(l < r) {
            int m = l + (r - l) / 2;
            if(target >= nums[m]) l = m + 1;
            else r = m;
        }
        return l;
    }
    
    private int lowerBound(int[] nums, int l, int r, int target) {
        while(l < r) {
            int m = l + (r - l) / 2;
            if(target > nums[m]) l = m + 1;
            else r = m;
        }
        return l;
    }
}
