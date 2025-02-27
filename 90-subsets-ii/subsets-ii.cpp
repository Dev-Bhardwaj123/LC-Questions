class Solution {
public:
    void solve(int ind,vector<int>& temp,vector<int>& nums,vector<vector<int>>& ans){
        ans.push_back(temp);
        for(int i=ind;i<nums.size();i++){
            //not take
            if(i!=ind && nums[i]==nums[i-1]){
                continue;
            }
            //take
            temp.push_back(nums[i]);
            solve(i+1,temp,nums,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        solve(0,temp,nums,ans);
        return ans;
    }
};