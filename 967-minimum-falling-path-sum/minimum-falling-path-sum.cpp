class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        
        for(int j=0;j<m;j++)
        {
            dp[0][j]=matrix[0][j];    
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int ld=1e9,rd=1e9;
                int up=matrix[i][j] + dp[i-1][j]; // going up
    
                if(j-1>=0) //check if possible
                    ld=matrix[i][j] + dp[i-1][j-1];  //going up left
                if(j+1<m)  //check if possible
                    rd=matrix[i][j] + dp[i-1][j+1]; //going up right
                
                dp[i][j] = min(up,min(ld,rd));   //update the min
            }
        }
        int mini=dp[n-1][0]; 
        
        for(int j=1;j<m;j++)
        {
            mini=min(mini,dp[n-1][j]); //finding min in last row
        }
        return mini;
    }
};