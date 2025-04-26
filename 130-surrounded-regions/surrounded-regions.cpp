class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>& board,vector<vector<int>>& vis,int dr[],int dc[]){
        vis[row][col]=1;
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+dr[i];
            int ncol=col+dc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(nrow,ncol,board,vis,dr,dc);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        //for rows boundary
        for(int j=0;j<m;j++){
            //First row
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0,j,board,vis,dr,dc);
            }
            //Last row
            if(!vis[n-1][j] && board[n-1][j]=='O'){
                dfs(n-1,j,board,vis,dr,dc);
            }
        }
        //for columns boundary
        for(int i = 0;i<n;i++) {
            // first column 
            if(!vis[i][0] && board[i][0] == 'O') {
                dfs(i,0,board,vis,dr,dc); 
            }
            
            // last column
            if(!vis[i][m-1] && board[i][m-1] == 'O') {
                dfs(i, m-1,board,vis,dr,dc); 
            }
        }
        // if unvisited O then convert to X
        for(int i = 0;i<n;i++) {
            for(int j= 0 ;j<m;j++) {
                if(!vis[i][j] && board[i][j] == 'O') 
                    board[i][j] = 'X'; 
            }
        }
    }
};