class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=0,high=nums.size()-1;
       while(low<=high){
            int mid=(low+high)/2;
            if((mid==0 || nums[mid-1]<nums[mid])&&(mid==nums.size()-1 || nums[mid]>nums[mid+1])){
                return mid;
            }
            else if(mid>0 && nums[mid-1]>=nums[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
       } 
       return -1;
    }
};