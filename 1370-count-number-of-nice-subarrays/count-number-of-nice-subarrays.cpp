class Solution {
public:
    int sumLessthanEq(vector<int>& nums,int goal){
        if(goal<0) return 0;
        int l=0,r=0,sum=0;
        int cnt=0;
        while(r<nums.size()){
            sum+=nums[r];
            while(sum>goal){
                sum=sum-nums[l];
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0){
                nums[i]=1;
            }
            else{
                nums[i]=0;
            }
        }
        int res=sumLessthanEq(nums,k)-sumLessthanEq(nums,k-1);
        return res;
    }
};