class Solution {
public:
    bool check(vector<vector<int>>& graph, int start, vector<int>& color) {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (auto k : graph[node]) {
                if (color[k] == -1) { 
                    color[k] = !color[node];
                    q.push(k);
                }
                else if (color[k] == color[node]) { 
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) { 
                if (!check(graph, i, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};
