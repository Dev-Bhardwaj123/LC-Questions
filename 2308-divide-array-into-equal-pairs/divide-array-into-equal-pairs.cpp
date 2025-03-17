class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int k=0;
        for(auto m:mp){
            if(m.second%2==0){
                k+=(m.second/2);
            }
            if(m.second%2!=0){
                return false;
            }
        }
        return true;
    }
};