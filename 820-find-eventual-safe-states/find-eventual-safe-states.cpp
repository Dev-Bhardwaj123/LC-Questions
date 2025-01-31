class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> adjRev(graph.size());
        vector<int> indegree(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            for(auto j:graph[i]){
                adjRev[j].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        vector<int> sfnodes;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int s=q.front();
            q.pop();
            sfnodes.push_back(s);
            for(auto k:adjRev[s]){
                indegree[k]--;
                if(indegree[k]==0){
                    q.push(k);
                }
            }
        }
        sort(sfnodes.begin(),sfnodes.end());
        return sfnodes;

    }
};