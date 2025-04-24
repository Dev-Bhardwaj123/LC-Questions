class Solution {
public:
    void bfs(vector<vector<int>>& adj,vector<bool>& visited,int node){
        queue<int> q;
        visited[node]=true;
        q.push(node);
        while(!q.empty()){
            int s=q.front();
            q.pop();
            for(auto& k:adj[s]){
                if(!visited[k]){
                    visited[k]=true;
                    q.push(k);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adj(isConnected.size());
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected.size();j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> visited(isConnected.size(),false);
        int cnt=0;
        for(int i=0;i<adj.size();i++){
            if(!visited[i]){
                bfs(adj,visited,i);
                cnt++;
            }
        }
        return cnt;
    }
};