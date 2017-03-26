//O(n^2)
public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new LinkedList<>();
        Arrays.sort(nums);
        for(int i = 0; i < nums.length; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int target = 0 - nums[i];
            
            int lo = i + 1, hi = nums.length - 1;
            while(lo < hi) {
                int sum = nums[lo] + nums[hi];
                if(sum < target) {
                    lo++;
                }
                else if(sum > target) {
                    hi--;
                } else {
                    while(lo < hi && nums[lo] == nums[lo + 1]) lo++;
                    while(lo < hi && nums[hi] == nums[hi - 1]) hi--;
                    ans.add(Arrays.asList(nums[i], nums[lo], nums[hi]));
                    lo++; hi--;
                }
            }
        }
        return ans;
    }
}
