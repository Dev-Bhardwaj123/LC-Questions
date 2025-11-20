class Solution {
public:
    int checkCnt(vector<int>& nums,int k,int sum){
        int cnt=1,cntVal=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]+cntVal<=sum){
                cntVal+=nums[i];
            }
            else{
                cnt++;
                cntVal=nums[i];
            }
        }
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            int res=checkCnt(nums,k,mid);
            if(res<=k){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};