class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0) return false;
        if(word.size() == 0) return true;
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> flag;
        vector<bool> tmp(m, 0);
        for(int i = 0; i < n; i++) flag.push_back(tmp);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] ==word[0] && dfs(board, word, flag, m, i, j, 1))
                    return true;
            }
        }
        return false;
    }
private:
    int d[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
    bool dfs(const vector<vector<char>> &board, const string &word, vector<vector<bool>> &flag, int m, int x, int y, int depth) {
        if(depth == word.size()) return true;
        flag[x][y] = true;
        for(int i = 0; i < 4; i++) {
            int nx = x + d[i][0], ny = y + d[i][1];
            if(nx < 0 || nx >= board.size() || ny < 0 || ny > board[0].size())
                continue;
            if(!flag[nx][ny] && board[nx][ny] == word[depth]) {
                //cout << "bug" << endl;
                if(dfs(board, word, flag, m, nx, ny, depth + 1))
                    return true;
            }
        }
        flag[x][y] = false;
        return false;
    }
};
