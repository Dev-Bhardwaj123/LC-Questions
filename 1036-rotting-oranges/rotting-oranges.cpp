class Solution {
public:
    bool valid(int i,int j,vector<vector<int>>& grid){
        return i>=0&&i<grid.size()&&j>=0&&j<grid[0].size()&&grid[i][j]==1;
    }
    int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int cnt=0;
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int c=q.size();
            cnt++;
            while(c--){
                auto d=q.front();
                int x=d.first;
                int y=d.second;
                q.pop();
                for(int i=0;i<4;i++){
                    int new_x=x+dir[i][0];
                    int new_y=y+dir[i][1];
                    if(valid(new_x,new_y,grid)){
                        grid[new_x][new_y]=2;
                        q.push({new_x,new_y});
                    }
                }
            }
        }
        for(auto i:grid){
            for(auto j:i){
                if(j==1){
                    return -1;
                }
            }
        }
        return cnt==0?0:cnt-1;
    }
};