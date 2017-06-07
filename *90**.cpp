class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans = {{}};
        int sz = 0, st = 0;
        for(int i = 0; i < nums.size(); i++) {
            int cur = nums[i];
            cout << i << ' ' << st << ' ' << sz << endl;
            st = i && cur == nums[i - 1] ? sz : 0;
            sz = ans.size();
            cout << i << ' ' << st << ' ' << sz << endl;
            for(int j = st; j < sz; j++) {
                vector<int> tmp = ans[j];
                // wrong
                //if(tmp.size() && tmp[tmp.size() - 1] != cur && i && nums[i - 1] == cur)  continue; 
                tmp.push_back(cur);
                ans.push_back(tmp);
            }
        }
        cout << endl;
        return ans;
    }
};
