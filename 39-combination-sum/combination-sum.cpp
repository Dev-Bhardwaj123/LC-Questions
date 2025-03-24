class Solution {
public:
    void solve(int i,int target,vector<int>& temp,vector<vector<int>>& res,vector<int>& candidates){
        if(i>=candidates.size() || target<0){
            return;
        }
        if(target==0){
            res.push_back(temp);
            return;
        }
        for(int ind=i;ind<candidates.size();ind++){
            temp.push_back(candidates[ind]);
            solve(ind,target-candidates[ind],temp,res,candidates);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(0,target,temp,res,candidates);
        return res;
    }
};