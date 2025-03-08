class Solution {
public:
    int solve(int i,int j,string word1,string word2,vector<vector<int>>& dp){
        if (i >= word1.length()) return word2.length() - j;
        if (j >= word2.length()) return word1.length() - i; 
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //if match then move ahead
        if(word1[i]==word2[j]){
            return dp[i][j]=solve(i+1,j+1,word1,word2,dp);
        }
        //insert
        int ins=1+solve(i,j+1,word1,word2,dp);
        //delete
        int del=1+solve(i+1,j,word1,word2,dp);
        //replace
        int rep=1+solve(i+1,j+1,word1,word2,dp);

        return dp[i][j]=min(ins,min(del,rep));
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(),vector<int>(word2.length(),-1));
        int z=solve(0,0,word1,word2,dp);
        return z;
    }
};