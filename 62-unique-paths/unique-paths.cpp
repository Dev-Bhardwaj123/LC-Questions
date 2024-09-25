class Solution {
public:
    int solve(int m,int n,int i,int j,vector<vector<int>>& dp){
        //base cond
        if(i==m-1 || j==n-1){
            return 1;
        }
        if(i>=m || j>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //go right
        int right=solve(m,n,i,j+1,dp);
        //go down
        int down=solve(m,n,i+1,j,dp);
        int ans=right+down;
        dp[i][j]=ans;
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp;
        for(int i=0;i<m;i++){
            vector<int> v;
            for(int j=0;j<n;j++){
                v.push_back(-1);
            }
            dp.push_back(v);
        }
        int res=solve(m,n,0,0,dp);
        return res;
    }
};