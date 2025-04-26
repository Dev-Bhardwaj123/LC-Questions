class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orColor=image[sr][sc];
        if(orColor==color) return image;
        image[sr][sc]=color;
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+dr[i];
                int ncol=c+dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==orColor){
                    image[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }
        }
        return image;
    }
};