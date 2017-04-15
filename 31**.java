public class Solution {
    public void nextPermutation(int[] nums) {
    // https://cloverii.github.io/2017-04-15/leetcode-31-next-permutation/
        if(nums.length == 0) return; // no such cases
        int len = nums.length;
        int k = len - 1;
        // everything to the right of nums[k - 1] is in nonincreasing order
        while(k > 0 && nums[k] <= nums[k - 1]) // avoid duplication
            k--;
        if(k == 0)
            reverse(nums, 0, len - 1);
        else {
            int i = 0;
            // find the number just larger than nums[k - 1]
            for(i = len - 1; ; i--) {
                if(nums[i] > nums[k - 1])
                    break;
            }
            // then swap them
            swap(nums, k - 1, i);
            reverse(nums, k, len - 1);
        }
    }
    
    private void reverse(int[] nums, int l, int r) {
        while(l < r)
            swap(nums, l++, r--);
    }
    
    private void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}
