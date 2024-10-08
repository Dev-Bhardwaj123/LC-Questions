class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int mini=prices[0];
        for(int i=1;i<prices.size();i++){
            int curr=0;
            if(prices[i]<mini){
                mini=prices[i];
            }
            curr=prices[i]-mini;
            profit=max(curr,profit);
        }
        return profit;
    }
};