class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> row,col;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(int r:row){
            for(int j=0;j<matrix[0].size();j++){
                matrix[r][j]=0;
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int c:col){
                matrix[i][c]=0;
            }
        }
        
    }
};