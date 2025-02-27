class Solution {
public:
    void sub(int ind,vector<int>& nums,vector<int>& temp,vector<vector<int>>& ans){
        //base case
        if(ind ==nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]); //take the element
        sub(ind+1,nums,temp,ans); //move further
        temp.pop_back(); //backtrack and remove
        sub(ind+1,nums,temp,ans); //move ahead once not taken
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sub(0,nums,temp,ans);
        return ans;
    }
};