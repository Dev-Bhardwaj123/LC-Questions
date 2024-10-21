class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<long long> dp(nums.size()+1,-1);
        return solve(0,nums,dp);
    }
    long long solve(long long i,vector<int>& nums,vector<long long>& dp){
        if(i>=nums.size()-1){
           return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        long long ans=0;
        if(nums[i]==0){
            return dp[i]=0;
        }
        for(int j=1;j<=nums[i];j++){
            if(solve(i+j,nums,dp)){
                return dp[i+j]=1;
            }
        }
        return dp[i]=0;
    }
};