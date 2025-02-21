class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int z=0;
        for(auto m:mp){
            if(m.second>1){
                z=m.first;
                break;
            }
        }
        return z;
    }
};