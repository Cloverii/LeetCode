public class Solution {
    public int removeElement(int[] nums, int val) {
        int ans = nums.length;
        for(int i = 0; i < ans; i++) {
            if(nums[i] == val) {
                while(ans > 0 && nums[ans - 1] == val) ans--;
                if(ans > 0) nums[i] = nums[ans - 1];
                if(i < ans) ans--;
            }
            /*while(nums[i] == val && i < ans) {
                nums[i] = nums[--ans];
            }*/
        }
        return ans;
    }
}
