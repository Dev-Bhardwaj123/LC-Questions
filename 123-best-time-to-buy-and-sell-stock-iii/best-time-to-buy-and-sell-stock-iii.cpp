class Solution {
public:
    int f(int ind,int buy,int k,vector<int>& prices,vector<vector<vector<int>>>& dp){
        if(ind==prices.size() || k==0){
            return 0;
        }
        if(dp[ind][buy][k]!=-1){
            return dp[ind][buy][k];
        }
        int profit=0;
        if(buy){
            profit=max(-prices[ind]+f(ind+1,0,k,prices,dp),0+f(ind+1,1,k,prices,dp));
        }
        else{
            profit=max(prices[ind]+f(ind+1,1,k-1,prices,dp),0+f(ind+1,0,k,prices,dp));
        }
        return dp[ind][buy][k]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int k=2;
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,k,prices,dp);
    }
};