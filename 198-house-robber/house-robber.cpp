class Solution {
public:
    int solve(vector<int>& nums,vector<int>& dp,int i){
        //base case
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        //take adj
        int rob=nums[i]+solve(nums,dp,i+2);
        //not take
        int nrob=solve(nums,dp,i+1);
        dp[i]=max(rob,nrob);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        int z=solve(nums,dp,0);
        return z;
    }
};