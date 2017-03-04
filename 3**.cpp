class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int flag[500];
        memset(flag, -1, sizeof(flag));
        int st = 0, ed = -1;
        for(int i = 0; i < s.size(); i++) {
            if(flag[s[i]] == -1) {
                ed++;
                flag[s[i]] = i;
            }
            else {
                st = max(flag[s[i]] + 1, st);
                flag[s[i]] = i;
                ed++;
            }
            cout << st << ' ' << ed << endl;
            ans = max(ans, ed - st + 1);
        }
        cout << endl;
        return ans;
    }
};
