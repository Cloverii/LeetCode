class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 0; bool flag = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(i && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < nums.size(); j++) {
                int tmp = target - nums[i] - nums[j];
                if(j - 1 != i && nums[j] == nums[j - 1]) continue;
                int k = lower_bound(nums.begin() + j + 1, nums.end(), tmp) - nums.begin();
                if(k != nums.size()) {
                    ans = cal(nums[i], nums[j], nums[k], target, ans, flag);
                }
                if(k > j + 1) ans = cal(nums[i], nums[j], nums[k - 1], target, ans, flag);
            }
        }
        return target - ans;
    }
    
    int cal(int a, int b, int c, int target, int ans, bool &flag) {
        if(!flag || flag && abs(target - a - b - c) < abs(ans)) { flag = 1;return target - a - b - c; }
        else return ans;
    }
};
