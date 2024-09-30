class Solution {
public:
    int f(int ind,int buy,int fee,vector<int>& prices,vector<vector<int>>& dp){
        if(ind>=prices.size()){
            return 0;
        }
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }
        int profit=0;
        if(buy){
            profit=max(-prices[ind]+f(ind+1,0,fee,prices,dp),0+f(ind+1,1,fee,prices,dp));
        }
        else{
            profit=max(prices[ind]-fee+f(ind+1,1,fee,prices,dp),0+f(ind+1,0,fee,prices,dp));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return f(0,1,fee,prices,dp);
    }
};