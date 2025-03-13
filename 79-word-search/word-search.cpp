class Solution {
public:
    bool finPath(vector<vector<char>>& board,string word,int x,int y,int wLen){
        if(wLen==word.length()){
            return true;
        }
        if(x<0 ||y<0 ||x>=board.size() || y>=board[0].size()){
            return false;
        }
        if(board[x][y]==word[wLen]){
            char temp=board[x][y];
            board[x][y]='#';
            bool res=finPath(board,word,x+1,y,wLen+1) || 
                     finPath(board,word,x,y+1,wLen+1) ||
                     finPath(board,word,x,y-1,wLen+1) ||
                     finPath(board,word,x-1,y,wLen+1);
            board[x][y]=temp;
            return res;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        if(n*m<word.length()) return false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(finPath(board,word,i,j,0)) return true;
                }
            }
        }
        return false;
    }
};