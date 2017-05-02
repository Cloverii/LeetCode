class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int l = 0, r = n - 1; l < n - 1 && r > 0; l++, r--) {
            for(int i = l; i < r; i++) {
                rotatePoint(matrix, l, i);
            }
        }
    }
    
    void rotatePoint(vector<vector<int>> & mp, int x, int y) {
        int n = mp.size();
        int tmp = mp[x][y];
        mp[x][y] = mp[n - y - 1][x];
        mp[n - y - 1][x] = mp[n - x - 1][n - y - 1];
        mp[n - x - 1][n - y - 1] = mp[y][n - x - 1];
        mp[y][n - x - 1] = tmp;
    }
};
