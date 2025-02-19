class Solution {
public:
    int solve(int i,int buy,vector<int>& prices,vector<vector<int>>& dp){
        //base case
        if(i==prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        int prof=0;
        //if bought then only one can sell
        if(buy){
            //maximize profit 
            //if bought then check case of selling and not selling
            prof=max(-prices[i]+solve(i+1,0,prices,dp),solve(i+1,1,prices,dp));
        }
        else{
            //if not bought check case of buying and not buying
            prof=max(prices[i]+solve(i+1,1,prices,dp),solve(i+1,0,prices,dp));
        }
        dp[i][buy]=prof;
        return dp[i][buy];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        int z=solve(0,1,prices,dp);
        return z;
    }
};