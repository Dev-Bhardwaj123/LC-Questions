class Solution {
public:
    void solve(vector<int>& nums,vector<int>& op,int ind,vector<vector<int>>& res){
        if(ind==nums.size()){
            res.push_back(op);
            return;
        }
        op.push_back(nums[ind]);
        solve(nums,op,ind+1,res);
        op.pop_back();
        solve(nums,op,ind+1,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> op;
        solve(nums,op,0,res);
        return res;
    }
};