class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        res[0]=1;
        int rp=1;
        for(int i=1;i<nums.size();i++){
            rp=rp*nums[i-1];
            res[i]=rp;
        }
        rp=1;
        for(int i=nums.size()-2;i>=0;i--){
            rp=rp*nums[i+1];
            res[i]*=rp;
        }
        return res;
    }
};