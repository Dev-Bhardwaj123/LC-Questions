class Solution {
public:

    //DFS solution
    void dfs(int row,int col,vector<vector<int>>& image,int newColor,int drow[],int dcol[],int ini){
        image[row][col]=newColor;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==ini){
                dfs(nrow,ncol,image,newColor,drow,dcol,ini);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ini=image[sr][sc];
        if(ini==color) return image;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        dfs(sr,sc,image,color,drow,dcol,ini);
        return image;
    }

    //BFS Solution
    // vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    //     int orColor=image[sr][sc];
    //     if(orColor==color) return image;
    //     image[sr][sc]=color;
    //     int n=image.size();
    //     int m=image[0].size();
    //     queue<pair<int,int>> q;
    //     q.push({sr,sc});
    //     int dr[]={-1,0,1,0};
    //     int dc[]={0,-1,0,1};
    //     while(!q.empty()){
    //         int r=q.front().first;
    //         int c=q.front().second;
    //         q.pop();
    //         for(int i=0;i<4;i++){
    //             int nrow=r+dr[i];
    //             int ncol=c+dc[i];
    //             if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==orColor){
    //                 image[nrow][ncol]=color;
    //                 q.push({nrow,ncol});
    //             }
    //         }
    //     }
    //     return image;
    // }
};