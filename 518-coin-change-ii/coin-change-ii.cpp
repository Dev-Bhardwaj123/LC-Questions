class Solution {
public:
    int solve(vector<int>& coins,int amount,int ind,vector<vector<int>>& dp){
        //base cond
        if(ind==0){
            return (amount%coins[0]==0);
        }
        if(dp[ind][amount]!=-1){
            return dp[ind][amount];
        }
        //not take case
        int notTake=solve(coins,amount,ind-1,dp);
        //take case
        int take=0;
        if(coins[ind]<=amount){
            take=solve(coins,amount-coins[ind],ind,dp);
        }
        return dp[ind][amount]=take+notTake;

    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int z=solve(coins,amount,n-1,dp);
        return z;
    }
};