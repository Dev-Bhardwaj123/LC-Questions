class Solution {
public:
    void solve(int ind,string& curr,unordered_map<int,vector<char>>& mp,string digits,vector<string>& temp){
        //base case
        if(ind==digits.length()){
            temp.push_back(curr);
            return;
        }
        for(char ch: mp[digits[ind]-'0']){
            //push the element in curr string
            curr.push_back(ch);
            //check for next index and till last
            solve(ind+1,curr,mp,digits,temp);
            //pop back the element
            curr.pop_back();

        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0){
            return ans;
        }
        unordered_map<int,vector<char>> mp;
        mp={{2,{'a','b','c'}},{3,{'d','e','f'}},{4,{'g','h','i'}},{5,{'j','k','l'}},{6,{'m','n','o'}},
            {7,{'p','q','r','s'}},{8,{'t','u','v'}},{9,{'w','x','y','z'}}};
        string curr="";
        solve(0,curr,mp,digits,ans);
        return ans;
    }
};