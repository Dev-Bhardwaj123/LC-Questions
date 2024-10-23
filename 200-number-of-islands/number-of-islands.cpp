class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid, int n, int m) {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        
        // Define directions for traversal (up, down, left, right)
        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int curRow = q.front().first;
            int curCol = q.front().second;
            q.pop();

            // Traverse 4 neighbors (up, down, left, right)
            for (int i = 0; i < 4; i++) {
                int nrow = curRow + drow[i];
                int ncol = curCol + dcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!vis[row][col] && grid[row][col] == '1') {
                    cnt++;
                    bfs(row, col, vis, grid, n, m);
                }
            }
        }

        return cnt;
    }
};
