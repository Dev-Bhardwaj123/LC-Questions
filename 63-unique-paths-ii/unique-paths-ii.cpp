class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid,int m,int n,int i,int j,vector<vector<int>>& dp){
        //base cond
        if(i==m-1 && j==n-1){
            if(obstacleGrid[i][j]==1){
                return 0;
            }
            else{
                return 1;
            }
        }
        //if obstacle found merged cond
        if(i>=m || j>=n ||  obstacleGrid[i][j]==1){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //go right
        int right=solve(obstacleGrid,m,n,i,j+1,dp);
        //go down
        int down=solve(obstacleGrid,m,n,i+1,j,dp);
        dp[i][j]=right+down;
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp;
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        for(int i=0;i<m;i++){
            vector<int> v;
            for(int j=0;j<n;j++){
                v.push_back(-1);
            }
            dp.push_back(v);
        }
        int ans=solve(obstacleGrid,m,n,0,0,dp);
        return ans;
    }
};