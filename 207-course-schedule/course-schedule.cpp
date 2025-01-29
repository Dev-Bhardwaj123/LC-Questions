class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto pre:prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }
        vector<int> indegree(adj.size(),0);
        for(int i=0;i<adj.size();i++){
            for(auto k:adj[i]){
                indegree[k]++;
            }
        }
        queue<int> q;
        for(int i=0;i<adj.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return cnt==numCourses;
    }
};