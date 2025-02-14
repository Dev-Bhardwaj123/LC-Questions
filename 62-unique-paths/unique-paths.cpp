class Solution {
public:
    int solve(int i,int j,int m,int n,vector<vector<int>>& dp){
        //base case
        if(i==m-1 && j==n-1){
            return 1;
        }
        //corner case
        if(i>=m || j>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //go down
        int down=solve(i+1,j,m,n,dp);
        //go right
        int right=solve(i,j+1,m,n,dp);
        dp[i][j]=down+right;
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int z=solve(0,0,m,n,dp);
        return z;
    }
};