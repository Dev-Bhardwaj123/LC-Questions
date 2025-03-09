class Solution {
public:
    int solve(int i,int j,int m,int n,vector<vector<int>>& grid,vector<vector<int>>& dp){
        //base case once it reaches
        if(i==m-1 && j==n-1){
            return grid[i][j];
        }
        //edge cases
        if(i>=m || j>=n){
            return 1e9;
        }
        //prechecks
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        //go down
        int down=grid[i][j]+solve(i+1,j,m,n,grid,dp);
        //go right
        int right=grid[i][j]+solve(i,j+1,m,n,grid,dp);
        ans=min(down,right);
        return dp[i][j]=ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int z=solve(0,0,m,n,grid,dp);
        return z;
    }
};