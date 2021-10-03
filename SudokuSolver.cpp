class Solution {
public:
    bool isSafe (vector<vector<char>> board, int cell, int r, int c) {
        for (int i=0; i<9; i++) {
            if (board[i][c] == cell) 
                return false;
            if (board[r][i]== cell) 
                return false;
        }
       
        for (int i=(r/3) * 3; i<(r/3) * 3+3; i++) {
            for (int j=(c/3) * 3; j<(c/3) * 3+3; j++) 
                if (board[i][j] == cell)
                    return false;
        }
        return true;
    }
    
    bool solve (vector<vector<char>>& board) {
         
         for (int i=0; i<9; i++) {
             for (int j=0; j<9; j++) {
                 if (board[i][j] != '.')
                     continue;
                 
                 for (char k='1'; k<='9'; k++)
                     if (isSafe (board, k, i, j)) {
                         board[i][j] = k;
                         if (solve (board))
                             return true;
                         board[i][j] = '.';  
                     }
                 return false;
             }
         }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve (board);
    }
};
