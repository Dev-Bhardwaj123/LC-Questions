class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i:nums){
            mp[i]++;
        }
        int mini=*min_element(nums.begin(),nums.end());
        if(k>mini) return -1;
        if(k==mini) return mp.size()-1;
        return mp.size();
    }
};