class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int i=0,j=n-1;
        int ind=0;
        while(i<n-1 && arr[i]<arr[i+1]){
            i++;
        }
        while(j>0 && arr[j]<arr[j-1]){
            j--;
        }
        if(i<n && j>0 && i==j){
            ind =i;
        }
        return ind;

    }
};