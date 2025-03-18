class Solution {
public:
    int solve(int i,int j,string word1,string word2,vector<vector<int>>& dp){
        if(i>=word1.length()) return word2.length()-j;
        if(j>=word2.length()) return word1.length()-i;
        if(word1[i]==word2[j]){
            return dp[i][j]=solve(i+1,j+1,word1,word2,dp);
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int inc=1+solve(i,j+1,word1,word2,dp);
        int dec=1+solve(i+1,j,word1,word2,dp);
        int rep=1+solve(i+1,j+1,word1,word2,dp);
        return dp[i][j]=min({inc,dec,rep});
    }
    int minDistance(string word1, string word2) {
        int n=word1.length(),m=word2.length();
        vector<vector<int>> dp(word1.length(),vector<int>(word2.length(),-1));
        return solve(0,0,word1,word2,dp);

    }
};