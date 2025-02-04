class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res=nums[0];
        int i=0;
        int j=1;
        int sum=nums[i];
        while(j<nums.size()){
            if(nums[i]<nums[j]){
                sum+=nums[j];
            }
            else{
                sum=nums[j];
            }
            i++;
            j++;
            res=max(res,sum);
        }
        return res;
    }
};