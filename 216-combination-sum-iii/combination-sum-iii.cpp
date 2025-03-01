class Solution {
public:
    void solve(int ind,int k,int n,vector<int>& temp,vector<vector<int>>& ans){
        if(n<0){
            return;
        }
        if(temp.size()==k){
            if(n==0) ans.push_back(temp);
            return;
        }
        for(int i=ind;i<=9;i++){
           if(n-i>=0){
            temp.push_back(i);
            solve(i+1,k,n-i,temp,ans);
            temp.pop_back();
           }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1,k,n,temp,ans);
        return ans;
    }
};