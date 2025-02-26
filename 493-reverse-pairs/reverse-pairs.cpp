class Solution { //OPTIMAL APPROACH,,,T-O(NLOGN * 2), S-O(N)
public: 


    void merge(vector<int>&arr, int low, int mid, int high){

        int left = low, right = mid+1; vector<int>temp;
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left++]);
            }
            else{
                temp.push_back(arr[right++]);
            }
        }

        //if left array left
        while(left <= mid){
            temp.push_back(arr[left++]);
        }
        while(right <= high){
            temp.push_back(arr[right++]);
        }

        //now pushing back the temp array elmenets to original array
        for(int i=low; i<=high;i++){
            arr[i] = temp[i - low];
        }

    }



    int countPairs(vector<int>&arr, int low, int mid, int high){

        int count=0, right=mid+1;
        for(int i = low;i <= mid; i++){
            while (right <= high && (long long)arr[i] > 2LL * arr[right]) right++;
            count += (right - (mid+1));
        }

        return count;
    }

    int mergeSort(vector<int>&arr, int low, int high){
        int count=0;

        if(low >= high) return count;
        int mid = (low + high)/2;
        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid+1, high);
        count += countPairs(arr, low, mid, high);
        merge(arr, low, mid, high);

        return count;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }
};