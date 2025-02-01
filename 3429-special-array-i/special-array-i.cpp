class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size()==1){
            return true;
        }
        bool check=true;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]%2!=0 && nums[i]%2!=0){
                check=false;
            }
            else if(nums[i-1]%2==0 && nums[i]%2==0){
                check=false;
            }
        }
        return check;
    }
};