class Solution {
public:
    void merge(int low,int mid, int high,vector<int>& nums){
        int n1=mid-low+1,n2=high-mid;
        vector<int> left(n1);
        vector<int> right(n2);
        for(int i=0;i<n1;i++){
            left[i]=nums[i+low];
        }
        for(int i=0;i<n2;i++){
            right[i]=nums[mid+1+i];
        }
        int i=0,j=0,k=low;
        while(i<n1 && j<n2){
            if(left[i]<=right[j]){
                nums[k]=left[i];
                i++;
                k++;
            }
            else{
                nums[k]=right[j];
                j++;
                k++;
            }
        }
        while(i<n1){
            nums[k]=left[i];
            i++;
            k++;
        }
        while(j<n2){
            nums[k]=right[j];
            j++;
            k++;
        }
    }
    void mergeSort(int l,int r,vector<int>& nums){
        if(l<r){
            int mid=l+(r-l)/2;
            mergeSort(l,mid,nums);
            mergeSort(mid+1,r,nums);
            merge(l,mid,r,nums);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0,nums.size()-1,nums);
        return nums;
    }
};