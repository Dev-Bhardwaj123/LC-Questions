class Solution {
public:
    bool checkValid(int row, int col, char c, vector<vector<char>>& board) {
        if (c == '.') return true; 
        for (int k = 0; k < 9; k++) {
            if (k != col && board[row][k] == c) return false; 
            if (k != row && board[k][col] == c) return false; 
        }
        int startRow = 3 * (row / 3);
        int startCol = 3 * (col / 3);
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if ((i != row || j != col) && board[i][j] == c) return false;
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (!checkValid(i, j, board[i][j], board)) {
                    return false;
                }
            }
        }
        return true; 
    }
};
