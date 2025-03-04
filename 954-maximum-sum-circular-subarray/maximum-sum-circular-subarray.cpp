class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxE=0,minE=0;
        int maxSum=nums[0],minSum=nums[0];
        int total=0;
        for(int i=0;i<nums.size();i++){
            maxE=max(maxE+nums[i],nums[i]);
            maxSum=max(maxE,maxSum);

            minE=min(minE+nums[i],nums[i]);
            minSum=min(minE,minSum);

            total+=nums[i];
        }
        int normSum=maxSum;
        int circSum=total-minSum;
        if(minSum==total){
            return normSum;
        }
        return max(normSum,circSum);
    }
};