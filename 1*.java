//O(n) average
public class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> mp = new HashMap<Integer, Integer>();
        for(int i = 0; i < nums.length; i++) {
            int tmp = target - nums[i];
            if(mp.containsKey(tmp)) {
                return new int[] {mp.get(tmp), i};
            } else {
                mp.put(nums[i], i);
            }
        }
        return new int[]{0, 0};
    }
}
