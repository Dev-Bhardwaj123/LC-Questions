class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum=0,minSum=0;
        for(int i=0;i<nums.size();i++){
            maxSum=max(0,maxSum+nums[i]);
            minSum=min(0,minSum+nums[i]);
        }
        return maxSum-minSum;
    }
};