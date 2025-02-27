class Solution {
public:
    void solve(int i,int target,vector<int>& candidates,vector<int>& temp,vector<vector<int>>& ans){
        //edge case
        if(i>=candidates.size() || target<0){
            return;
        }
        //base case
        if(target==0){
            ans.push_back(temp);
            return;
        }
        for(int ind=i;ind<candidates.size();ind++){
            temp.push_back(candidates[ind]);
            solve(ind,target-candidates[ind],candidates,temp,ans); //same check for that element only
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(0,target,candidates,temp,res);
        return res;
    }   
};