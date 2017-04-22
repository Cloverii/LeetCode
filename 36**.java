public class Solution {
    public boolean isValidSudoku(char[][] board) {
        for(int i = 0; i < 9; i += 3) {
            for(int j = 0; j < 9; j += 3) {
                if(!checkSquare(board, i, j)) return false;
            }
        }
        return checkRowAndCol(board);
    }
    
    private boolean checkSquare(char[][] mp, int x, int y) {
        int flag = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(mp[x + i][y + j] == '.') continue;
                int cur = Character.getNumericValue(mp[x + i][y + j]);
                if((flag >> cur) > 0) return false;
                flag |= (1 << cur);
            }
        }
        return true;
    }
    
    private boolean checkRowAndCol(char[][] mp) {
        int flag = 0;
        for(int i = 0; i < 9; i++) {
            flag = 0;
            for(int j = 0; j < 9; j++) {
                if(mp[i][j] == '.') continue;
                int cur = Character.getNumericValue(mp[i][j]);
                if((flag >> cur) > 0) return false;
                flag |= (1 << cur);
            }
            flag = 0;
            for(int j = 0; j < 9; j++) {
                if(mp[j][i] == '.') continue;
                int cur = Character.getNumericValue(mp[j][i]);
                if((flag >> cur) > 0) return false;
                flag |= (1 << cur);
            }
        }
        return true;
    }
}
