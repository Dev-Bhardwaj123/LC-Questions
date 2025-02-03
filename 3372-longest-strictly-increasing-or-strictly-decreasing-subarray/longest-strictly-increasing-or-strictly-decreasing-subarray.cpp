class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int incri=1;
        int decri=1;
        int maxi=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                incri++;
                decri=1;
            }
            else if(nums[i-1]>nums[i]){
                decri++;
                incri=1;
            }
            else{
                incri=1;
                decri=1;
            }
            maxi=max(maxi,max(incri,decri));
        }
        return maxi;
    }
};