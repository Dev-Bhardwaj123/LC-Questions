class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(arr[0]<=sum){
            dp[0][arr[0]]=true;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool notTake=dp[i-1][j];
                bool take=false;
                if(arr[i]<=j) take=dp[i-1][j-arr[i]];
                dp[i][j]=take||notTake;
            }
        }
        return dp[n-1][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int target=sum/2;
        if(sum%2!=0) return false;
        return isSubsetSum(nums,target);
    }
};