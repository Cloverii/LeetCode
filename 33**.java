public class Solution {
    public static int search(int[] nums, int target) {
        if(nums == null || nums.length == 0) return -1;
        int l = 0, r = nums.length - 1; //[l,r]
        while(l < r) {
            int m = l + (r - l) / 2;
            if(nums[l] <= nums[m]) {
                if(target >= nums[l] && target <= nums[m]) r = m;
                else l = m + 1;
            } else {
                if(target > nums[m] && target <= nums[r]) l = m + 1;
                else r = m ;
            }

        }
        if(nums[l] != target) l = -1;
        return l;
    }
    
    public int search1(int[] nums, int target) { // original code
        if(nums == null) return -1;
        int id = findPivot(nums);
        int res = lowerBound(nums, 0, id, target);
        if(res == -1) 
            res = lowerBound(nums, id, nums.length, target);
        return res;
    }
    
    private int findPivot(int[] nums) {
        int cnt = 0;
        int l = 0, r = nums.length; //[l,r)
        while(l < r) {
            int m = l + (r - l) / 2;
            if(nums[m] <= nums[nums.length - 1]) r = m;
            if(nums[m] >= nums[0]) l = m + 1;
        }
        return l;
    }
    
    private int lowerBound(int[] nums, int l, int r, int target) {
    	int rr = r;
        while(l < r) { //[l,r)
            int m = l + (r - l) / 2;
            if(target > nums[m]) l = m + 1;
            else r = m;
        }
        if(l == rr || nums[l] != target) return -1;
        return l;
    }

}
