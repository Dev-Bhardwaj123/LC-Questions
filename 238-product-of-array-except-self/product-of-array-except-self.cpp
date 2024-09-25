class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int prearr[nums.size()];
        prearr[0]=1;
        for(int i=1;i<nums.size();i++){
            prearr[i]=prearr[i-1]*nums[i-1];
        }
        int sufarr[nums.size()];
        sufarr[nums.size()-1]=1;
        for(int i=nums.size()-2;i>=0;i--){
            sufarr[i]=sufarr[i+1]*nums[i+1];
        }
        for(int i=0;i<nums.size();i++){
            res.push_back(prearr[i]*sufarr[i]);
        }
        return res;
    }
};