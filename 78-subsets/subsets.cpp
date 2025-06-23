class Solution {
public:
    void solve(int i,vector<int> temp,vector<vector<int>>& res,vector<int>& nums){
        if(i==nums.size()){
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(i+1,temp,res,nums);
        temp.pop_back();
        solve(i+1,temp,res,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;   
        solve(0,temp,res,nums);
        return res;
    }
};