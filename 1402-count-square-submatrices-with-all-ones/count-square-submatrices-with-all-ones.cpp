class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        //base case
        if(i<0 || j<0 || matrix[i][j]==0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        dp[i][j]=1+min({solve(i-1,j,matrix,dp),solve(i-1,j-1,matrix,dp),solve(i,j-1,matrix,dp)});
        return dp[i][j];
    }
    int countSquares(vector<vector<int>>& matrix) {
        int r=matrix.size(),c=matrix[0].size();
        vector<vector<int>> dp(r,vector<int>(c,-1));
        int cnt=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cnt+=solve(i,j,matrix,dp);
            }
        }
        return cnt;
    }
};