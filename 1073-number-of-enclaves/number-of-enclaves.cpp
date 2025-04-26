class Solution {
public:
    void bfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis,int dr[],int dc[],int n,int m){
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+dr[i];
                int ncol=c+dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }

    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};

        vector<vector<int>> vis(n,vector<int>(m,0));
        // Step 1: First do BFS for boundary cells
        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]==1){
                bfs(i,0,grid,vis,dr,dc,n,m);
            }
            if(!vis[i][m-1] && grid[i][m-1]==1){
                bfs(i,m-1,grid,vis,dr,dc,n,m);
            }
        }
        for(int j=0;j<m;j++){
            if(!vis[0][j] && grid[0][j]==1){
                bfs(0,j,grid,vis,dr,dc,n,m);
            }
            if(!vis[n-1][j] && grid[n-1][j]==1){
                bfs(n-1,j,grid,vis,dr,dc,n,m);
            }
        }
        
        // Step 2: Now count the unvisited 1's
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};