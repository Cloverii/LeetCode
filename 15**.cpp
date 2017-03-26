// O(n^2logn)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int a[3];
        for(int i = 0; i < nums.size(); i++) {
            if(i && nums[i] == nums[i - 1]) continue; // duplicate
            for(int j = i + 1; j < nums.size(); j++) {
                if(j - 1 != i && nums[j] == nums[j - 1]) continue; //duplicate
                int tmp = 0 - nums[i] - nums[j];
                vector<int>::iterator it = lower_bound(nums.begin() + j + 1, nums.end(), tmp);
                if(it != nums.end()) a[2] = *it; 
                else continue;
                a[0] = nums[i], a[1] = nums[j];
                vector<int> v(a, a + 3);
                if(a[2] == tmp) ans.push_back(v);
            }
        }
        return ans;
    }
};
