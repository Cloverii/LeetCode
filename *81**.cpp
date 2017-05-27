class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0;
        int l = 0, r = nums.size() - 1; // [l,r]
        while(l < r) {
            int m = l + (r - l) / 2;
            if(target == nums[m]) return true;
            if(nums[m] == nums[l] && nums[m] == nums[r]) {
                for(int i = l; i <= r; i++) 
                    if(nums[i] == target) return true;
                return false;
            } 
            else if(nums[r] < nums[m]) {
                if(target >= nums[l] && target <= nums[m]) r = m;
                else l = m + 1;
            } else {
                if(target > nums[m] && target <= nums[r]) l = m + 1;
                else r = m ;
            }
        }
        return nums[l] == target;// nums.length can't be 0
    }
};
