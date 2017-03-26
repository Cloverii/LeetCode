//O(n^2)
class Solution {
    typedef pair<int, int> Pair;
    bool cmp (const Pair &x, const Pair &y) {
        return x.first < y.first || 
            x.first == y.first && x.second < y.second;
    }
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int arr[2];
        for(int i = 0; i < nums.size(); i++) {
            int tmp = target - nums[i];
            for(int j = i; j < nums.size(); j++) 
                if(tmp == nums[j]) {
                    arr[0] = i, arr[1] = j;
                    break;
                }
        }
        vector<int> ans(arr, arr + 2);
        return ans;
    }
};
