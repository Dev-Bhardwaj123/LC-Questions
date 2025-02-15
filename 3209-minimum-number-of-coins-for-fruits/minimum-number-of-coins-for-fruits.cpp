class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n=prices.size();
        vector<int> dp(n+1,1e9);
        dp[0]=0;
        for(int i=0;i<n;i++){
            int buy=dp[i]+prices[i];
            for(int j=i+1;j<=(2*i+2) && j<=n;j++){
                dp[j]=min(dp[j],buy);
            }
        }
        return dp[n];
    }
};