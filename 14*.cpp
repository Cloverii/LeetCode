class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        for(int j = 0; strs.size() > 0; j++) { // j: 0 -> min(strs[i].size()
            if(check(j, strs)) ans += strs[0][j];
            else return ans;
        }
        return ans;
    }
    
    bool check(int num, vector<string>& strs) {
        char pre;
        for(int i = 0; i < strs.size(); i++) {
            if(num > strs[i].size()) return 0;
            if(i == 0) pre = strs[i][num];
            if(pre != strs[i][num]) return 0;
        }
        return 1;
    }
};
