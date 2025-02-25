class Solution {
public:
    bool isSafe(int row,int col,char c,vector<vector<char>>& board){
        //go through all rows in 9x9 grid
        for(int i=0;i<9;i++){
            //check same row
            if(board[row][i]==c) return false;
            //check for same col
            if(board[i][col]==c) return false;
            //check in 3*3 sub grid
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                //if cell empty
                if(board[i][j]=='.'){
                    for(char k='1';k<='9';k++){
                        if(isSafe(i,j,k,board)){
                            board[i][j]=k;
                            if(solve(board)) {
                                return true;
                            }
                            board[i][j]='.'; //backtrack step
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};