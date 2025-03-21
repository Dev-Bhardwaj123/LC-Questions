class Solution {
public:
    //Memoization
    // bool solve(int i,int j,string s,string p,vector<vector<int>>& dp){
    //     //base cases
    //     if(i<0 && j<0){
    //         return true;
    //     }
    //     if(j<0 && i>=0){
    //         return false;
    //     }
    //     if(i<0 && j>=0){
    //         for(int k=0;k<=j;k++){
    //             if(p[k]!='*'){
    //                 return false;
    //             }
    //         }
    //         return true;
    //     }
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     //ifn match found
    //     if(s[i]==p[j] || p[j]=='?'){
    //         return dp[i][j]=solve(i-1,j-1,s,p,dp);
    //     }
    //     if(p[j]=='*'){
    //         return dp[i][j]=solve(i-1,j,s,p,dp)|solve(i,j-1,s,p,dp);
    //     }
    //     else{
    //         return dp[i][j]=false;
    //     }
    // } 
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        //vector<vector<int>> dp(n,vector<int>(m,-1));

        //Tabulation
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        //base case 1
        dp[0][0]=true;
        //base case 2 (string remains but pattern exhausted)
        for(int i=1;i<=n;i++){
            dp[i][0]=false;
        }
        //base case 3(string exhausted but flag remains)
        for(int j=1;j<=m;j++){
            bool flag=true;
            for(int k=1;k<=j;k++){
                if(p[k-1]!='*'){
                    flag=false;
                    break;
                }
            }
            dp[0][j]=flag;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    dp[i][j]=dp[i-1][j]|dp[i][j-1];
                }
                else{
                    dp[i][j]=false;
                }
            }
        }
        return dp[n][m];

    }
};