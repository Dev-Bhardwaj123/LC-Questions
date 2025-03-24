class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd=nums[0],minProd=nums[0],ans=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                swap(minProd,maxProd);
            }
            maxProd=max(maxProd*nums[i],nums[i]);
            minProd=min(minProd*nums[i],nums[i]);
            ans=max(ans,maxProd);
        }
        return ans;
    }
};