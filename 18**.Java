// Two pointers O(n^3)
public class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        return NSum(4, nums, 0, target);
    }
    
    private ArrayList<List<Integer>> NSum(int n, int[] nums, int begin, int target) {
        ArrayList<List<Integer>> ans = new ArrayList<List<Integer>>();
        if(n == 2) {
            int lo = begin; int hi = nums.length - 1;
            while(lo < hi) {
                int sum = nums[lo] + nums[hi];
                if(sum < target) {
                    lo++;
                }
                else if(sum > target) {
                    hi--;
                } else {
                    ans.add(new LinkedList<Integer>(Arrays.asList(nums[lo], nums[hi])));
                    while(lo < hi && nums[lo] == nums[lo + 1]) lo++;
                    while(lo < hi && nums[hi] == nums[hi - 1]) hi--;
                    lo++; hi--;
                }
            }
        } else {
            List<List<Integer>> tmp/* = new ArrayList<>()*/;
            for(int i = begin; i < nums.length - n + 1; i++) {
                if(nums[i] * n > target) break;
                tmp = NSum(n - 1, nums, i + 1, target - nums[i]);
                if(!tmp.isEmpty()) {
                    for(List<Integer> l: tmp) {
                        l.add(0, nums[i]);
                    }
                    ans.addAll(tmp);
                }
                while(i < nums.length - 1 && nums[i] == nums[i + 1]) i++;
            }
        }
        return ans;
    }
}
