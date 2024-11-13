class Solution {
public:
    bool valid(int x,int y,vector<vector<int>>& mat){
        return x>=0&&x<mat.size()&&y>=0&&y<mat[0].size()&&mat[x][y];
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> dist(mat.size(),vector<int>(mat[0].size(),INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(!mat[i][j]){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
               int new_x=x+dir[i][0];
               int new_y=y+dir[i][1];
               if(valid(new_x,new_y,mat)){
                    if(dist[x][y]+1<dist[new_x][new_y]){
                        dist[new_x][new_y]=dist[x][y]+1;
                        q.push({new_x,new_y});
                    }
               }
            }

        }
        return dist;
    }
};