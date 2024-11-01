class Solution {
public:
    int lessEqual(vector<int>&nums,int goal){
        int l=0,r=0,sum=0,cnt=0;
        if(goal<0){
            return 0;
        }
        while(r<nums.size()){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return lessEqual(nums,goal)-lessEqual(nums,goal-1);
    }
};