class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& image,vector<vector<int>>& ans,int newColor,int drow[],int dcol[],int ini){
        ans[row][col]=newColor;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==ini && ans[nrow][ncol]!=newColor){
                dfs(nrow,ncol,image,ans,newColor,drow,dcol,ini);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ini=image[sr][sc];
        vector<vector<int>> ans=image;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        dfs(sr,sc,image,ans,color,drow,dcol,ini);
        return ans;
    }
};