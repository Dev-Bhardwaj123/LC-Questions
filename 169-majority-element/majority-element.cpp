class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0,res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==nums[res]){
                cnt++;
            }
            else{
                cnt--;
            }
            if(cnt==0){
                res=i;
                cnt=1;
            }
        }
        cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==nums[res]){
                cnt++;
            }
        }
        return nums[res];
    }
};