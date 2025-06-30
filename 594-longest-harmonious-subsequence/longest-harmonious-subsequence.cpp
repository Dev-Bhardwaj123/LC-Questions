class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j=1;
        int cnt=0;
        while(j<n){
            if(nums[j]-nums[i]<1){
                j++;
            }
            else if((nums[j]-nums[i])==1){
                j++;
                cnt=max(cnt,j-i+1);
            }
            else{
                i++;
            }
        }

        return (cnt>0)? cnt-1: cnt;
    }
};