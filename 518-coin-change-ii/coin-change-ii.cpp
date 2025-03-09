class Solution {
public:
    int solve(int amount,vector<int>& coins,int i,vector<vector<int>>& dp){
        //base condition, terminates when all cases checked
        if(i==0){
            return (amount%coins[0]==0);
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        int notTake=solve(amount,coins,i-1,dp);
        int take=0;
        if(amount>=coins[i]){
            take=solve(amount-coins[i],coins,i,dp);
        }
        return dp[i][amount]=take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(amount,coins,n-1,dp);
    }
};