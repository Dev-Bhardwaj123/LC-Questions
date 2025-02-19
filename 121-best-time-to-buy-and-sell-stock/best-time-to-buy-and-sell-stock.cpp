class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pro=0;
        int mini=prices[0];
        for(int i=1;i<prices.size();i++){
            int curr=0; //tracks indi profit
            if(prices[i]<mini){//finds lowest to buy
                mini=prices[i];
            }
            curr=prices[i]-mini; //max difference
            pro=max(pro,curr);//compares and find max
        }
        return pro;
    }
};