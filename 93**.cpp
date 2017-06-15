class Solution {
private:
    bool check(const string &s, int st, int ed) {
        int val = 0;
        if(ed - st > 1 && s[st] == '0') return false;
        for(int i = st; i < ed; ++i)
            val = val * 10 + s[i] - '0';
        return val <= 255;
    }
    void helper(vector<string> &ans, string tmp, const string &s, int cur, int archive) {
        if(cur == s.size() && archive == 4) {
            ans.push_back(tmp);
            return;
        }
        if(s.size() - cur < 4 - archive || s.size() - cur > (4 - archive) * 3) return;
        if(archive) tmp += '.';
        for(int i = 1; i < 4 && cur + i <= s.size(); ++i) {
            int ed = cur + i;
            if(check(s, cur, ed)) {
                tmp += s.substr(cur, i);
                helper(ans, tmp, s, ed, archive + 1);
                tmp.resize(tmp.size() - i);
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string tmp;
        helper(ans, tmp, s, 0, 0);
        return ans;
    }
};
