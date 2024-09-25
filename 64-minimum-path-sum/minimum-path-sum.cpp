class Solution {
public:
    int solve(vector<vector<int>>& grid,int m,int n,int i,int j,vector<vector<int>>& dp){
        //base cond
        if(i==m-1 && j==n-1){
            return grid[i][j];
        }
        if(i>=m || j>=n){
            return 1e9;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //go right
        int right=grid[i][j]+solve(grid,m,n,i,j+1,dp);
        //go down
        int down=grid[i][j]+solve(grid,m,n,i+1,j,dp);
        //check min
        int ans=min(right,down);
        dp[i][j]=ans;
        //update
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp;
        for(int i=0;i<m;i++){
            vector<int> v;
            for(int j=0;j<n;j++){
                v.push_back(-1);
            }
            dp.push_back(v);
        }
        int res=solve(grid,m,n,0,0,dp);
        return res;
    }
};