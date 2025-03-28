class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0,high=(matrix.size()*matrix[0].size())-1;
        while(low<=high){
            int mid=(low+high)/2;
            int midV=matrix[mid/matrix[0].size()][mid%matrix[0].size()];
            if(midV==target){
                return true;
            }
            else if(midV<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
            return false;
    }
};