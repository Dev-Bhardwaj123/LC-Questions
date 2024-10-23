class Solution {
public:
    void dfs(int node,vector<int>&vis, vector<vector<int>>&ls){
        vis[node]=1;
        for(auto nbr:ls[node]){
            if(vis[nbr]==0){
                dfs(nbr,vis,ls);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt=0;
        int V =isConnected.size();
        vector<vector<int>>ls(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1&&i!=j){
                    ls[i].push_back(j);
                }
            }
        }
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]==0)
            {
                cnt++;
                dfs(i,vis,ls);
            }
        
        }
        return cnt;
    }
};