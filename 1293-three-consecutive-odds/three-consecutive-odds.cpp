class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int i=2;
        while(i<arr.size()){
            if(arr[i-2]%2!=0 && arr[i-1]%2!=0 && arr[i]%2!=0){
                return true;
            }
            i++;
        }
        return false;
    }
};