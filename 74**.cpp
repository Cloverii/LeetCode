class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n - 1;
        while(x < m && y >= 0) {
            if(matrix[x][y] == target) return true;
            else if(matrix[x][y] > target) y--;
            else if(matrix[x][y] < target) x++;
        }
        return false;
    }
};
