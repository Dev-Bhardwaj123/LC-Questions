class Solution {
public:
    int f(int ind,int sum,vector<int>& arr,vector<vector<int>>& dp){
        if(ind==0){
            if(sum==0 && arr[0]==0) return 2;
            if(sum==0 || sum==arr[0]) return 1;
            return 0;
        }
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        int notTake=f(ind-1,sum,arr,dp);
        int take=0;
        if(arr[ind]<=sum) take=f(ind-1,sum-arr[ind],arr,dp);
        
        return dp[ind][sum]=notTake+take;
    }
    int findWays(vector<int>& arr,int tar){
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(tar+1,-1));
        
        return f(n-1,tar,arr,dp);
    }
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int totSum=0;
        for(auto &it:arr){
            totSum+=it;
        }
        if(totSum-d<0 || (totSum-d)%2) return false;
        return findWays(arr,(totSum-d)/2);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums,target);
    }
};