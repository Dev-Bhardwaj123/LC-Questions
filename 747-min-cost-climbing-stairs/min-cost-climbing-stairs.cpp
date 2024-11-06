class Solution {
public:
    int solve(vector<int>& cost, int i,vector<int>& dp){
        if(i>=cost.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        //take 1
        int take=cost[i]+solve(cost,i+1,dp);
        //take 2
        int take2=cost[i]+solve(cost,i+2,dp);
        int ans=min(take,take2);
        return dp[i]=ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        int x=min(solve(cost,0,dp),solve(cost,1,dp));
        
        return x;
    }
};