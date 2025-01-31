class Solution {
public:
    void bfs(vector<vector<int>>& adj,vector<bool>& vis,int node){
        queue<int> q;
        vis[node]=true;
        q.push(node);
        while(!q.empty()){
            int s=q.front();
            q.pop();
            for(auto j: adj[s]){
                if(!vis[j]){
                    vis[j]=true;
                    q.push(j);
                }
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adjL(isConnected.size());
        vector<bool> vis(isConnected.size(),false);
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected.size();j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjL[i].push_back(j);
                    adjL[j].push_back(i);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<adjL.size();i++){
            if(!vis[i]){
                bfs(adjL,vis,i);
                cnt++;
            }
        }
        return cnt;
    }
};