class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> cost(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    cost[i][j]=0;
                }
            }
        }
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            cost[u][v]=wt;
            cost[v][u]=wt;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(cost[i][k]==1e9 || cost[k][j]==1e9){
                        continue;
                    }
                    cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
                }
            }
        }
        int cityMax=n;
        int city=-1;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(cost[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<=cityMax){
                cityMax=cnt;
                city=i;
            }
        }
        return city;
        
    }
};