public class Solution {
    public int searchInsert(int[] nums, int target) {
        int l = 0, r = nums.length - 1;
        while(l < r) {
            int mid = l + r >> 1; //***
            if(target > nums[mid]) {
                l = mid + 1; //**
            } else {
                r = mid; //
            }
        }
        if(l == nums.length - 1 && target > nums[l] ) l++;
        return l;
    }
}
