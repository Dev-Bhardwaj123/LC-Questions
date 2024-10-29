class Solution {
public:
    int solve(int i,int j,int prev,vector<vector<int>>& grid,int n,int m,vector<vector<int>>& dp){
        //base cond
        if(i<0 || i>=n || j>=m){
            return 0;
        }
        int x=grid[i][j];
        if(x<=prev){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=max(solve(i-1,j+1,x,grid,n,m,dp),max(solve(i,j+1,x,grid,n,m,dp),solve(i+1,j+1,x,grid,n,m,dp)))+1;
        return dp[i][j]=ans;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,solve(i,0,-1,grid,n,m,dp));
        }
        return ans-1;
    }
};