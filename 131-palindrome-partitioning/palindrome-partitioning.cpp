class Solution {
public:
    bool isPalindrome(string s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    void solve(int ind,vector<string>& temp,string s,vector<vector<string>>& ans){
        //base case when partition bar reaches out of length
        if(ind==s.length()){
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<s.length();i++){
            if(isPalindrome(s,ind,i)){
                temp.push_back(s.substr(ind,i-ind+1));
                solve(i+1,temp,s,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0,temp,s,ans);
        return ans;
    }
};