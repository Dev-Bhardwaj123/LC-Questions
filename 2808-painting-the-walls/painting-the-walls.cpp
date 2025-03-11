class Solution {
public:
    int paint(int i,int walls,vector<int>& cost,vector<int>& time,vector<vector<int>>& dp){
        if(walls<=0){
            return 0;
        }
        if(i==cost.size()){
            return 1000000000;
        }
        if(dp[i][walls]==-1){
            dp[i][walls]=min(paint(i+1,walls,cost,time,dp),cost[i]+paint(i+1,walls-time[i]-1,cost,time,dp));
        }
        return dp[i][walls];
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<vector<int>> dp(cost.size(),vector<int>(cost.size()*4,-1));
        return paint(0,time.size(),cost,time,dp);
    }
};