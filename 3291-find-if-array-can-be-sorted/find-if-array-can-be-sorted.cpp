class Solution {
public:
    bool checkBits(int a,int b){
        int cnt1=0,cnt2=0;
        while(a>0){
            if(a%2!=0){
                cnt1++;
            }
            a=a/2;
        }
        while(b>0){
            if(b%2!=0){
                cnt2++;
            }
            b=b/2;
        }
        return cnt1==cnt2;
    }
    bool canSortArray(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size()-i-1;j++){
                if(nums[j]>nums[j+1]){
                    if(checkBits(nums[j],nums[j+1])){
                        swap(nums[j],nums[j+1]);
                    }
                }
            }
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                return false;
            }
        }
        return true;
    }
};