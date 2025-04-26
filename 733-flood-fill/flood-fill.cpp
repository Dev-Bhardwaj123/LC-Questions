class Solution {
public:
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
};