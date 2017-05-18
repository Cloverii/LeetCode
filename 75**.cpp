class Solution {
public:
    void sortColors(vector<int>& nums) {
        // elements on the left of l (included) is 0,
        // and those on the right of r (included) is 2;
        // element between (l, i) is 1
        int l = -1, r = nums.size();
        int i = 0;
        while(i < r) { // nums[r] = 2 (or null)
            if(nums[i] == 2)
                swap(nums[--r], nums[i]);
            else {
                if(nums[i] == 0) 
                    swap(nums[++l], nums[i]);
                ++i;
            }
        }
    }
};
