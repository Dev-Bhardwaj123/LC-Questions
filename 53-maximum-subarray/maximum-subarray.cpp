class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxE=nums[0],ans=nums[0];
        for(int i=1;i<nums.size();i++){
            maxE=max(maxE+nums[i],nums[i]);
            ans=max(ans,maxE);
        }
        return ans;
    }
};