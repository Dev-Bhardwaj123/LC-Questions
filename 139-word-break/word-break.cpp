class Solution {
public:
    bool solve(string s,unordered_set<string>& set,vector<int>& memo,int start){
        if(start==s.size()){
            return true;
        }
        if(memo[start]!=-1){
            return memo[start];
        }
        for(int i=start;i<s.size();i++){
            if(set.count(s.substr(start,i+1-start))&&solve(s,set,memo,i+1)){
                memo[start]=true;
                return true;
            }
        }
        return memo[start]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memo(s.size(),-1);
        unordered_set<string> set(wordDict.begin(),wordDict.end());
        return solve(s,set,memo,0);
    }
};