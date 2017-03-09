class Solution {
public:
    string convert(string s, int numRows) {
        if(s.size() < 2 || numRows == 1) return s; //**
        string ans;
        char mp[s.size()][numRows];
        memset(mp, 0, sizeof(mp));
        int x = 0, y = 0;
        for(int i = 0; i < s.size(); i++) {
            int mod = i % (numRows * 2 - 2);
            mp[x][y] = s[i];
            if(mod < numRows - 1) y++;
            else x++, y--;
        }
        for(int j = 0; j < numRows; j++) 
            for(int i = 0; i <= x; i++) 
                if(mp[i][j]) ans += mp[i][j];
        return ans;
    }
};
