class Solution {
public:
    int dijkstra(vector<vector<int>>& grid,queue<pair<int,pair<int,int>>> &q,vector<vector<int>>& dist,int n){
        int x_row[]={-1,-1,0,1,1,1,0,-1};
        int x_col[]={0,1,1,1,0,-1,-1,-1};
        while(!q.empty()){
            int distance=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();

            for(int i =0;i<8;i++){
                int new_row=row +x_row[i];
                int new_col=col +x_col[i];

                if(new_row>=0 && new_row<n && new_col>=0 && new_col <n && 
                    grid[new_row][new_col]==0 && distance + 1 <dist[new_row][new_col]){

                            dist[new_row][new_col]=distance + 1;
                            q.push({distance+1,{new_row,new_col}});

                    }
            }
        }
        return dist[n-1][n-1]==INT_MAX?-1 :dist[n-1][n-1];
    }


    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        queue<pair<int,pair<int,int>>>q;

        dist[0][0]=1;
        q.push({1,{0,0}});

        return dijkstra(grid,q,dist,n);
    }
};
