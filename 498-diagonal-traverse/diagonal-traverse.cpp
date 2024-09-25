class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row=0;
        int col=0;
        int dir=0;
        int m=mat.size();
        int n=mat[0].size();
        int ans[m*n];
        int idx=0;
        while(idx<m*n){
            ans[idx++]=mat[row][col];
            if(dir==0){
                if(col==n-1){
                    row++;
                    dir=1;
                }
                else if(row==0){
                    col++;
                    dir=1;
                }
                else{
                    row--;
                    col++;
                }
            }
            else{
                if(row==m-1){
                    col++;
                    dir=0;
                }
                else if(col==0){
                    row++;
                    dir=0;
                }
                else{
                    row++;
                    col--;
                }
            }
        }
        vector<int> v;
        for(int i=0;i<m*n;i++){
            v.push_back(ans[i]);
        }
        return v;
    }
};