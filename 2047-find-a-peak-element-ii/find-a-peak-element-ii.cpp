class Solution {
public:
    int findMaxInd(vector<vector<int>>& mat,int n,int m,int col){
        int maxV=-1;
        int ind=-1;
        for(int i=0;i<n;i++){
            if(mat[i][col]>maxV){
                maxV=mat[i][col];
                ind=i;
            }
        }
        return ind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0,high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int maxRInd=findMaxInd(mat,n,m,mid);
            int left= mid-1 >=0 ? mat[maxRInd][mid-1] : -1;
            int right= mid+1 < m ? mat[maxRInd][mid+1] : -1;
            if(mat[maxRInd][mid] >left && mat[maxRInd][mid]>right){
                return {maxRInd,mid};
            }
            else if(mat[maxRInd][mid]<left){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return {-1,-1};
    }
};