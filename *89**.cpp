class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans(1, 0);
        int cur = -1;
        while(++cur < n) {
            int sz = ans.size();
            for(int i = sz - 1; i >= 0; i--)
                ans.push_back(ans[i] ^ (1 << cur));
        }
        return ans;
    }
};
